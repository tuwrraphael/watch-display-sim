const fs = require("fs"),
    PNG = require("pngjs").PNG;

fs.createReadStream("../img/transit.png")
    .pipe(new PNG({
        filterType: 4
    }))
    .on("parsed", function () {
        var bytes = [];
        var byte = 0;
        var bitIndex = 0;
        for (var x = 0; x < this.width; x++) {
            for (var y = this.height - 1; y >= 0; y--) {
                var idx = (this.width * y + x) << 2;
                console.log(`idx : ${bitIndex} (${x},${y}): ${this.data[idx]}`);
                if (this.data[idx] === 0) {
                    byte |= 1 << bitIndex;
                }
                bitIndex++;
                if (bitIndex == 32) {
                    bytes.push(byte);
                    bitIndex = 0;
                    byte = 0;
                }
            }
        }
        bytes.push(byte);
        function buf2hex(buffer) { // buffer is an ArrayBuffer
            return Array.prototype.map.call(new Uint32Array(buffer), x => "0x" + x.toString(16)).join(',');
          }
        console.log(buf2hex(bytes));
    });