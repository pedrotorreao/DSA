/****************************************************************/
/* Utility functions for the Kruskal Algorithm ********/
/****************************************************************/

/****************************************************************/
/*************** Sorting Algorithm - Quick Sort *****************/
function quickSort(array, p = 0, q = array.length - 1) {
  //base case: if we've gone through all the array (or subarray for the recursive
  //calls), i.e., low position (p) have reached the high position (q), we're done.
  if (p < q) {
    //partition the array around the pivot (usually last element):
    let r = partition(array, p, q);
    //recursively call quickSort() for subarray with elements smaller than pivot.
    quickSort(array, p, r - 1);
    //recursively call quickSort() for subarray with elements greater than pivot.
    quickSort(array, r + 1, q);
  }
}

/**
 * Makes sure that all elements smaller than the pivot are on the left,
 * and all elements greater than the pivot are on right.
 */
function partition(array, p, q) {
  let pivot = q; //last element in the array
  let j = p; //first element in the array
  let i = p - 1; //pivot position after the partitioning

  while (j <= q) {
    if (array[j][2] <= array[pivot][2]) {
      ++i;
      [array[i], array[j]] = [array[j], array[i]];
    }
    ++j;
  }
  return i;
}
/****************************************************************/

/****************************************************************/
/****************** Disjoint Set Union (DSU) ********************/
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
/****************************************************************/

//export { dsu, quickSort, partition };
module.exports.dsu = dsu;
module.exports.quickSort = quickSort;
module.exports.partition = partition;
