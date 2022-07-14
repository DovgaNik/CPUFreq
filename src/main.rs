use std::fs::File;
use std::io::{prelude::*, BufReader};
use std::{thread, time};

const FILE_PATH: &str = "/proc/cpuinfo";
const DELIMITER: char = ':';

fn main() {

    loop {

        get_freq();
        thread::sleep(time::Duration::from_secs(2));

    }

}

fn get_freq() {

    let mut average: (u16, f32) = (0, 0.0); // Declaring a tuple to contain the number of cores and the sum of Hz.

    let file = File::open(FILE_PATH).unwrap(); //|This blob of code opens the file with CPU 
    let reader = BufReader::new(file);         //|information.

    for (_, line) in reader.lines().enumerate() {

        let line = line.unwrap();
        let split: Vec<&str> = line.split(DELIMITER).collect();

        if split[0] == "cpu MHz		"{

            let freq = split[1].trim().parse::<f32>().unwrap();
            
            println!("Core {core} is {coreFreq} GHz", core = average.0, coreFreq = freq / 1000.0);

            average.1 = average.1 + freq;
            average.0 = average.0 + 1;

        }

    }
    
    println!("The average frequency among the cores is {averageHz} GHz", averageHz = average.1 / average.0 as f32 / 1000.0);

}
