fn main() {
    let num: i64 = 13; // the number we are searching for
    let v: Vec<i64> = vec![1, 3, 6, 8, 13, 24, 42];
    let v_len: i64 = v.len() as i64;

    println!("There are {} items in the vector", v_len);
    println!("Number {} is at position {}", num, binsearch(num, v, v_len));
}

// binsearch() - binary search
//
// @num - number we are looking for
// @v - vector to search within
// @v_len - number of items in the vector
fn binsearch(num: i64, v: Vec<i64>, v_len: i64) -> i64 {
    let mut low: i64 = 0;
    let mut high: i64 = v_len - 1;
    let mut mid: i64 = (low + high) / 2;

    while low <= high {
        if num < v[mid as usize] {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }

    if num != v[mid as usize] {
        return -1; // no match
    }

    mid
}
