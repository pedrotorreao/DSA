class dsu {
  constructor() {
    this.parent = [];
    this.size = [];

    this.all = new Map();
  }
  /* ---- basic functionality ---- */

  /**
   * Create a new set.
   * @param {string} setVal unique identifier to name the new set.
   */
  make_set(setVal) {
    if (this.is_present(setVal)) {
      throw new Error(
        `... set ${setVal} already exists. Please choose an unique name.`
      );
    }
    this.parent[setVal] = setVal;
    this.size[setVal] = 1;

    this.all.set(setVal, true);
  }

  /**
   * Find representative of the set containing element 'setVal'.
   * @param {string} setVal identifier of the set that is being searched.
   * @returns set's representative name.
   */
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

  /**
   * Merge two existing sets.
   * @param {string} setA name of the first set to be merged.
   * @param {string} setB name of the second set to be merged.
   * @returns new set's representative name.
   */
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

  /**
   * Checks if a given element is present on a set.
   * @param {string} setVal name of the element to be checked.
   * @returns boolean indicating whether the element is already on the set.
   */
  is_present(setVal) {
    return this.all.has(setVal);
  }

  /**
   * Check if two elements belong to the same set.
   * @param {string} setA identifier for the first element.
   * @param {string} setB identifier for the second element.
   * @returns boolean indicating whether the elements are in the same set.
   */
  is_same(setA, setB) {
    if (this.find_set(setA) === this.find_set(setB)) {
      return true;
    }
    return false;
  }

  /**
   * Get the rank/size of an existing set.
   * @param {string} setVal identifier for an element belonging to the set.
   * @returns integer indicating the rank/size of the set.
   */
  get_rank(setVal) {
    if (!this.is_present(setVal)) {
      throw new Error(`... set ${setVal} does not exist.`);
    }
    return this.size[setVal];
  }

  /**
   * Get the representative of the set to which 'setVal' belong to.
   * @param {string} setVal identifier for the element to which look for the parent.
   * @returns string for the parent's name.
   */
  get_parent(setVal) {
    return this.find_set(setVal);
  }

  /**
   * Get all the children of a particular element/set.
   * @param {string} setVal identifier for the element/set being checked.
   * @returns array containing all chilren
   */
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

// create new disjoint set union - dsu:
let dsuTest = new dsu();

// make sets:
dsuTest.make_set("A");
dsuTest.make_set("B");
dsuTest.make_set("C");
dsuTest.make_set("D");

// test #1 - verify the creation of the sets:
console.log(dsuTest); // parent[] = [A: 'A', B: 'B', C: 'C', D: 'D']

// merge sets:
dsuTest.union_set("A", "B"); // size[A] = size[B]: parent[B] = A
dsuTest.union_set("A", "C"); // size[A] > size[C]: parent[C] = A
dsuTest.union_set("D", "B"); // size[D] < size[B]: parent[D] = A

// test #2 - verify the union of the sets:
console.log(dsuTest); // parent[] = [A: 'A', B: 'A', C: 'A', D: 'A']

// test #3 - checks the protection against repeated identifiers:
// dsuTest.make_set("B"); // it should throw an error.

// test #4 - checks the method for getting the representative of a set:
console.log(dsuTest.get_parent("D")); // should return 'A'.

// test #5 - checks the method for getting the children of an element:
console.log(dsuTest.get_children("A")); // should return ['B','C','D']

// make more sets:
dsuTest.make_set("X");
dsuTest.make_set("Y");
dsuTest.make_set("W");
dsuTest.make_set("Z");
dsuTest.make_set("K");
dsuTest.make_set("Q");

// merge more sets:
dsuTest.union_set("W", "Y"); // size[W] = size[Y]: parent[Y] = W
dsuTest.union_set("X", "Z"); // size[X] = size[Z]: parent[Z] = X
dsuTest.union_set("Q", "W"); // size[W] > size[Q]: parent[Q] = W
dsuTest.union_set("Z", "Q"); // size[Z] < size[Q]: parent[Z] = W
dsuTest.union_set("K", "D"); // size[K] < size[D]: parent[K] = A
dsuTest.union_set("C", "Z"); // size[C] > size[Z]: parent[Z] = A

// test #6 - verify the creation and union of the sets:
console.log(dsuTest);

// test #7 - checks if the union method is validating the sets:
// dsuTest.union_set("C", "H"); // should throw an error indicating that H is not a set.

// test #8 - double checks the method for getting the children of an element:
console.log(dsuTest.get_children("A")); // all sets are children of set A after path compression.

// test #9 - checks whether two elements belong to the same set:
console.log(dsuTest.is_same("C", "X")); // should return true

// test #10 - checks whether an element is present in the set:
console.log(dsuTest.is_present("M"));

// test #11 - checks whether it is possible to search for a non-existing element:
// console.log(dsuTest.find_set("M")); // should throw an error.

// test #12 - checks if find_set returns the correct representative:
console.log(dsuTest.find_set("Z")); // should return 'A'.

// test #13 - checks if get_rank returns the correct size:
console.log(dsuTest.get_rank("A"));
