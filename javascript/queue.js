function Queue () {
    collection = [];
    
    //print 
    this.print = function () {
        console.log(collection);
    };

    //enqueue
    this.enqueue = function (e) {
        collection.push(e);
    };

    //dequeue
    this.dequeue = function () {
        return collection.shift();
    };

    //front : return top of queue.
    this.front = function () {
        return collection[0];
    };

    //length
    this.length = function () {
        return collection.length;
    };

    //isEmpty : true if queue is empty.
    this.isEmpty = function () {
        return (collection.length === 0);
    };
};

var q = new Queue(); 
q.enqueue('a'); 
q.enqueue('b');
q.enqueue('c');
q.print();
q.dequeue();
console.log(q.front());
q.print();