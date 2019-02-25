const fs = require("fs");
const PNG = require("pngjs").PNG;
const commandLineArgs = require('command-line-args');
var path = require('path');

function buf2hex(buffer) {
    return Array.prototype.map.call(new Uint32Array(buffer), x => "0x" + x.toString(16)).join(',\n\t');
}

const optionDefinitions = [
    { name: "dir", type: String },
    { name: "prefix", type: String },
    { name: "header", type: Boolean },
    { name: "out", type: String },
];

const options = commandLineArgs(optionDefinitions);
var bytes = [];
var byte = 0;
var bitIndex = 0;
var byteIndex = 0;
var images = [];
fs.readdir(options.dir, (err, files) => {
    if (err) {
        console.error("Could not read directory.");
    }
    var promises = files.map(file => {
        var ext = path.extname(file);
        if (ext.toLowerCase() == ".png") {
            return new Promise(function (resolve) {
                fs.createReadStream(path.join(options.dir, file))
                    .pipe(new PNG({
                        filterType: 4
                    }))
                    .on("parsed", function () {
                        var img = {
                            width: this.width,
                            height: this.height,
                            name: file.replace(ext, ""),
                            startBit: bitIndex,
                            startByte: byteIndex
                        };
                        images.push(img);
                        for (var x = 0; x < this.width; x++) {
                            for (var y = this.height - 1; y >= 0; y--) {
                                var idx = (this.width * y + x) << 2;
                                if (this.data[idx] === 0) {
                                    byte |= 1 << bitIndex;
                                }
                                bitIndex++;
                                if (bitIndex == 32) {
                                    bytes.push(byte);
                                    byteIndex++;
                                    bitIndex = 0;
                                    byte = 0;
                                }
                            }
                        }
                        resolve();
                    });
            });
        }
        else {
            return Promise.resolve();
        }
    });
    Promise.all(promises).then(function () {
        if (0 != bitIndex) {
            bytes.push(byte);
        }
        var content;
        function imgName(v){
            return `${options.prefix ? options.prefix + "_" : ""}${v.name}`;
        }
        if (options.header) {
            content = `#ifndef IMG_GEN_ASSETS_H
#define IMG_GEN_ASSETS_H
#include "packed_image.h"

${images.map(v => `extern const packed_image_t ${imgName(v)};`).join("\n")}

#endif`;

        } else {
            content = `#include "packed_image.h"
#include <stdint.h>

const uint32_t data[] = {${buf2hex(bytes)}};

${images.map(v => `const packed_image_t ${imgName(v)} = {
    .startByte = ${v.startByte},
    .startBit = ${v.startBit},
    .width = ${v.width},
    .height = ${v.height},
    .data = &data};`).join("\n\n")}`;
        }
        fs.writeFileSync(options.out, content, "utf8");
    });
});
