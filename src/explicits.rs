use rand::Rng;

pub fn _randd() {
    let mut rng = rand::thread_rng();

    let n1: u8 = rng.gen();
    println!("Random u8: {}", n1);
    println!("Random u32: {}", rng.gen::<u32>());
    //print with range[1 to 4]
    let _n2: u8 = rand::thread_rng().gen_range(1..5);
}
use std::collections::HashMap;
pub struct Player {
    pub name: String,
    pub health: i32,
    pub attack: i32,
    pub heal: i32,
    pub powers: HashMap<String, i32>,
}

impl Player {
    pub fn default() -> Player {
        Player {
            name: String::from(""),
            health: 100,
            attack: rand::thread_rng().gen_range(16..20),
            heal: rand::thread_rng().gen_range(16..20),
            powers: HashMap::from([(String::from("Freeze"), 6), (String::from("Lava"), 8)]),
        }
    }

    pub fn stats(&self) {
        let mut powers: Vec<String> = self.powers.clone().into_keys().collect();
        powers.sort_unstable();
        println!("Name: {}\nHealth: {}\nAttack: {}\nPowers: {:?}", self.name.trim(), self.health, self.attack, powers);
    }

    pub fn power_iter(&self) {
        for (keys, value) in self.powers.iter() {
            println!("{}: {}", keys, value);
        }
    }

    pub fn heal(&mut self) {
        self.health += self.heal;
    }
}
