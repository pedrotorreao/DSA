class dsu {
  constructor() {
    this.parent = [];
    this.size = [];

    this.all = new Map();
  }
  /* ---- basic functionality ---- */

  make_set(setVal) {
    this.parent[setVal] = setVal;
    this.size[setVal] = 1;

    this.all.set(setVal, true);
  }

  find_set(setVal) {
    if (!this.is_present(setVal)) {
      throw new Error(`... set ${setVal} does not exist.`);
    }

    if (setVal === this.parent[setVal]) {
      return setVal;
    }
    // path compression:
    return (this.parent[setVal] = this.find_set(this.parent[setVal]));
  }

  union_set(setA, setB) {
    let setA_Parent = this.find_set(setA);
    let setB_Parent = this.find_set(setB);

    if (setA_Parent !== setB_Parent) {
      // union by rank:
      if (this.get_rank(setA_Parent) < this.get_rank(setB_Parent)) {
        this.parent[setA_Parent] = setB_Parent;
        this.size[setB_Parent] =
          this.size[setB_Parent] + this.size[setA_Parent];

        return;
      }
      this.parent[setB_Parent] = setA_Parent;
      this.size[setA_Parent] = this.size[setA_Parent] + this.size[setB_Parent];

      return;
    }
  }

  /* ---- helper methods ---- */

  is_present(setVal) {
    return this.all.has(setVal);
    // return typeof this.parent[setVal] !== undefined;
  }

  is_same(setA, setB) {
    if (this.find_set(setA) === this.find_set(setB)) {
      return true;
    }
    return false;
  }

  get_rank(setVal) {
    if (!this.is_present(setVal)) {
      throw new Error(`... set ${setVal} does not exist.`);
    }
    return this.size[setVal];
  }

  get_parent(setVal) {
    return this.find_set(setVal);
  }

  get_children(setVal) {
    let children = [];
    let keysIterator = this.all.keys();

    for (const key of keysIterator) {
      if (key !== setVal && this.find_set(key) === setVal) {
        children.push(key);
      }
    }

    return children;
  }
}

let dsuTest = new dsu();

dsuTest.make_set("A");
dsuTest.make_set("B");
dsuTest.make_set("C");
dsuTest.make_set("D");

dsuTest.union_set("A", "B");
dsuTest.union_set("A", "C");
dsuTest.union_set("D", "B");

// console.log(dsuTest);
// console.log(dsuTest.get_parent("D"));
// console.log(dsuTest.get_children("A"));

dsuTest.make_set("X");
dsuTest.make_set("Y");
dsuTest.make_set("W");
dsuTest.make_set("Z");
dsuTest.make_set("K");
dsuTest.make_set("Q");

dsuTest.union_set("W", "Y");
dsuTest.union_set("X", "Z");
dsuTest.union_set("Q", "W");
dsuTest.union_set("Z", "Q");

dsuTest.union_set("K", "D");

//dsuTest.union_set("C", "Z");

//console.log(dsuTest);
//dsuTest.union_set("C", "H");
//console.log(dsuTest.get_parent("Q"));
//console.log(dsuTest.get_children("A"));
console.log(dsuTest.get_children("A"));
// console.log(dsuTest.get_children("A"));
// console.log(dsuTest.is_same("C", "X"));
// console.log(dsuTest.is_present("M"));
// console.log(dsuTest.find_set("M"));
//console.log(dsuTest.find_set("C"));
//dsuTest.union_set("G", "B");
//console.log(dsuTest.get_rank("A"));
