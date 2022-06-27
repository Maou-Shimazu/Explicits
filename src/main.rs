mod explicits;
use explicits::{Monster, Player};
use fsio::*;
use std::{
    path::Path,
};
use std::io::{stdout, stdin, Write};
fn main() {
    if !Path::new(&explicits::configfile()).exists() {
        let mut player = Player::default();
        file::ensure_exists(&explicits::configfile()).expect("Could not create config file.");
        println!("Welcome to Explicits!");
        print!("What is your name: ");
        use std::io::{stdout, stdin, Write};
        stdout().flush().ok();
        stdin().read_line(&mut player.name).ok();
        println!("Welcome to your Explicit journey!");
        player.write_config();
    } else {
        let mut player: Player = Player::load_config();
        player.power_iter();
        println!();
        println!("Default Heath: {}", player.health);
        player.heal();
        println!("New Heath: {}", player.health);
        println!();
        player.stats();

        println!();
        let mut monster = Monster::default();
        player.attack(&mut monster);
        monster.stats();
        println!();

        monster.attack(&mut player);
        player.stats();

        player.write_config();
    }

    //println!("{}", explicits::configfile())
}
