use rand::{prelude::SliceRandom, Rng};
use configparser::ini::Ini;
use std::collections::HashMap;
use std::{
    fs::File,
};
use fsio::file;


pub fn _randd() {
    let mut rng = rand::thread_rng();

    let n1: u8 = rng.gen();
    println!("Random u8: {}", n1);
    println!("Random u32: {}", rng.gen::<u32>());
    //print with range[1 to 4]
    let _n2: u8 = rand::thread_rng().gen_range(1..5);
}

pub fn configfile() -> String {
    let configdir = dirs::config_dir()
        .unwrap()
        .into_os_string()
        .into_string()
        .unwrap()
        .replace('"', "")
        .replace("\\", "/");
    format!("{}/explicits/config.ini", configdir)
}

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

    
    #[allow(dead_code)]
    pub fn write_config(&self){
        if !file::ensure_exists(&configfile()).is_ok() {
            File::create(&configfile()).expect("Could not create config file."); 
            // some welcome new player thing
        }
        let mut ini = Ini::new();
        ini.set("player", "name", Some(self.name.trim().clone().to_owned()));
        ini.set("player", "health", Some(self.health.to_string()));
        ini.set("player", "attack_range", Some(self.attack.to_string()));
        ini.set("player", "heal_range", Some(self.heal.to_string()));
        for (section, keys) in &self.powers {
            ini.set("player.powers", section.as_str(), Some(keys.to_string()));
        }
        ini.set("player", "map", Some(String::new()));
        ini.write(configfile()).unwrap();
    }

    pub fn load_config() -> Player {
        let mut ini = Ini::new();
        ini.load(&configfile()).unwrap();
        Player {
            name: ini.get("player", "name").unwrap(),
            health:  ini.get("player", "health").unwrap().parse().unwrap(),
            attack: ini.get("player", "attack_range").unwrap().parse().unwrap(),
            heal: ini.get("player", "heal_range").unwrap().parse().unwrap(),
            powers: /*ini.get("player", "powers").unwrap().parse().unwrap(),*/HashMap::from([(String::from("Freeze"), 6), (String::from("Lava"), 8)]), // todo: fix powers
            death_message: Vec::new(),
        }
    }
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
// todo: stat system ✅️