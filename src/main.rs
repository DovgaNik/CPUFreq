use std::fs::File;
use std::io::{prelude::*, BufReader};

const FILE_PATH: &str = "/proc/cpuinfo";
const DELIMITER: char = ':';

fn main() {

	let mut average: (u16, f32) = (0, 0.0); // Declaring a tuple to contain the number of cores and the sum of Hz
	
	let file = File::open(FILE_PATH).unwrap();
	let reader = BufReader::new(file);

	for (_, line) in reader.lines().enumerate() {
	
	    let line = line.unwrap();
        let split: Vec<&str> = line.split(DELIMITER).collect();
        
        if split[0] == "cpu MHz		"{

            average.0 = average.0 + 1;
            average.1 = average.1 + split[1].trim().parse::<f32>().unwrap();

            //let temp = split[1].trim().parse::<f32>().unwrap();

        }
	}

	println!("{}", average.0);
	println!("{}", average.1);
}
