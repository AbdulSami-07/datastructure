function PriorityQueue () {
    let collection = [];
    
    //print
    this.print = () => console.log(collection);

    //isEmpty 
    this.isEmpty = () => {
        return (collection.length === 0);
    };

    //enqueue
    this.enqueue = (e) => {
        if (this.isEmpty()) {
            collection.push(e);
        }
        else {
            let added = false;
            for (let i = 0 ; i < collection.length ; i++) {
                if ( e[1] < collection[i][1] ) {
                    collection.splice(i,0,e);                    
                    added = true;
                    break;
                }
            }
            if (!added){
                collection.push(e);
            }
        }
    };

    //dequeue
    this.dequeue = () => {
        let result = collection.shift();
        return result[0];
    };

    //front
    this.front = () => {
        return collection[0];
    };

    //length
    this.size = () => function() {
        return collection.length;
    };
};

var pq = new PriorityQueue(); 
pq.enqueue(['Beau Carnes', 2]); 
pq.enqueue(['Quincy Larson', 3]);
pq.enqueue(['Ewa Mitulska-Wójcik', 1])
pq.enqueue(['Briana Swift', 2])
pq.print();
pq.dequeue();
console.log(pq.front());
pq.print();