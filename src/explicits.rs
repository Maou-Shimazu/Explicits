use rand::{prelude::SliceRandom, Rng};

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
    pub death_message: Vec<String>,
}

pub struct Monster {
    pub name: String,
    pub health: i32,
    pub attack: i32,
    pub names: Vec<String>,
    pub death_message: Vec<String>,
}

impl Player {
    pub fn default() -> Player {
        Player {
            name: String::new(),
            health: 100,
            attack: rand::thread_rng().gen_range(16..20),
            heal: rand::thread_rng().gen_range(16..20),
            powers: HashMap::from([(String::from("Freeze"), 6), (String::from("Lava"), 8)]),
            death_message: Vec::new(),
        }
    }

    pub fn stats(&self) {
        let mut powers: Vec<String> = self.powers.clone().into_keys().collect();
        powers.sort_unstable();
        println!(
            "Name: {}\nHealth: {}\nAttack: {}\nPowers: {:?}",
            self.name.trim(),
            self.health,
            self.attack,
            powers
        );
    }

    pub fn power_iter(&self) {
        for (keys, value) in self.powers.iter() {
            println!("{}: {}", keys, value);
        }
    }

    pub fn heal(&mut self) {
        self.health += self.heal;
    }

    pub fn attack(&self, mut m: &mut Monster) {
        m.health -= self.attack
    }
    #[allow(dead_code)]
    pub fn power_up(){}
}

impl Monster {
    pub fn default() -> Monster {
        let mut m = Monster {
            name: String::new(),
            health: 100,
            attack: rand::thread_rng().gen_range(16..20),
            names: vec![
                String::from("Marx"),
                String::from("Bambino"),
                String::from("Kale"),
                String::from("Maou-isa-troll"),
            ],
            death_message: Vec::new(),
        };
        m.name = m.names.choose(&mut rand::thread_rng()).unwrap().to_owned(); 
        m
    }

    pub fn stats(&self) {
        println!(
            "Name: {}\nHealth: {}\nAttack: {}\nPowers: ",
            self.name.trim(),
            self.health,
            self.attack
        );
    }

    pub fn attack(&self, mut p: &mut Player) {
        p.health -= self.attack
    }
}

// todo: impl stats from configuration
// todo: add leveling system for user and monster
// todo: add powerups with random damage and cool catchphrases. ✅
// todo: create implimentation of getch();
// todo: dehardcode values and add them to a public class scope
// warning: player's and monsters only die in option 1 of the switch, impliment
// a global check. 🛑 
// todo: stat system ✅️