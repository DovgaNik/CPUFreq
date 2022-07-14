use std::fs::File;
use std::io::{self, prelude::*, BufReader};

const FILE_PATH: &str = "/proc/cpuinfo";

fn main() {

    let average: (u16, u32); // Declaring a tuple to contain the number of cores and the sum of Hz

    let file = File::open(FILE_PATH).unwrap();
    let reader = BufReader::new(file);

    for (index, line) in reader.lines().enumerate() {
        let line = line.unwrap();
        
        println!("{}", line);
    }


}
