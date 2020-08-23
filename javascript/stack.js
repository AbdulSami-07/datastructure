let Stack = function () {
    this.count = 0;
    this.databank = {};

    //push
    this.push = function (data) {
        this.databank[this.count] = data;
        this.count++;
    };

    //pop
    this.pop = function () {
        if ( this.databank[this.count] === 0){
            return undefined;
        }
        else{
            this.count--;
            let result = this.databank[this.count];
            delete this.databank[this.count];
            return result;
        }

    };

    //peek
    this.peek = function () {
        return this.databank[this.count-1];
    };

    //length
    this.length = function () {
        return this.count;
    }
};

