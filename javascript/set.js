let Set = function () {

    let collection = [];

    //has : return true or false.
    this.has = function (e) {
        return (collection.indexOf(e) !== -1 );
    };

    //values : return all values in set.
    this.values = function () {
        return collection;
    };

    //add : add a new value to set.
    this.add = function (e) {
        if (!this.has(e)){
            collection.push(e);
            return true;
        }
        return false;
    };

    //remove : remove the given value from set.
    this.remove = function (e) {
        let i = collection.indexOf(e);
        if (i !== -1 ){
            collection.splice(i,1);
            return true;
        }
        return false;
    };

    //length : return size of set.
    this.length = function () {
        return collection.length;
    };

    //union : return union of given set.
    this.union = function (otherSet) {
        let unionSet = new Set();
        let firstSet = this.values();
        let secondSet = otherSet.values();
        firstSet.forEach(function (e){
            unionSet.add(e);
        });
        secondSet.forEach(function (e) {
            unionSet.add(e);
        });
        return unionSet;
    };

    //intersection : will return intersection of given array.
    this.intersection = function (otherSet) {
        let intersectionSet = new Set();
        let firstSet = this.values();
        firstSet.forEach(function (e) {
            if (otherSet.has(e)){
                intersectionSet.add(e);
            }
        });
        return intersectionSet;
    };

    //difference
    this.difference = function (otherSet) {
        let differenceSet = new Set();
        this.values().forEach(function (e) {
            if (!otherSet.has(e)){
                differenceSet.add(e);
            }
        });
        return differenceSet;
    };

    //subset : check if given set is subset of original set.
    this.subset = function (otherSet) {
        return this.values().every(function (e) {
                    return otherSet.has(e);
                });
    };

};
