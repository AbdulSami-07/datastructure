const hash = (string,max) =>{
    let hash = 0;
    for (let i = 0 ; i < string.length; i++){
        hash += string.charCodeAt(i);
    }
    return hash % max;
}

let HashTable = function () {
    let storage = [];
    const storageLimit = 14;

    this.add = function (key,value) {
        let index = hash(key,storageLimit);
        if(storage[index] === undefined){
            storage[index] = [[key,value]];
        }else {
            let inserted = false;
            for (let i = 0; i < storage[index].length; i++){
                if(storage[index][i][0] === key){
                    storage[index][i][1] = value;
                    inserted = true;
                }
            }
            if(inserted === false){
                storage[index].push([key,value]);
            }
        }
    };

    this.remove = function (key) {
        let index = hash(key,storageLimit);
        if (storage[index][0][0] === key && storage[index].length === 1){
            delete storage[index][0];
        }else{
            for (let i = 0 ; i < storage[index].length ; i++){
                if (storage[index][i][0] === key){
                    delete storage[index][i];
                }
            }
        }
    };

    this.lookup = (key) => {
        let index = hash(key,storageLimit);
        if(storage[index] === undefined){
            return undefined;
        }
        else {
            for (let i = 0 ; i < storage[index].length;i++){
                if (storage[index][i][0] === key ){
                    return storage[index][i][1];
                }
            }
        }
    };

    this.print = function() {
        console.log(storage)
      }
}

console.log(hash('quincy', 10))

let ht = new HashTable();
ht.add('beau', 'person');
ht.add('fido', 'dog');
ht.add('rex', 'dinosour');
ht.add('tux', 'penguin');
// console.log(hash('tux',14));
console.log(ht.lookup('tux'));
ht.print();