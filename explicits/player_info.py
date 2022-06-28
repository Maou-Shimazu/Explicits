from __future__ import annotations
from .config import Config
import random
 #TODO: write funcs to retrieve values from config file(s)
 #TODO: remove unions after creating first_time user page. 
config = Config()
class Player():
    def __init__(self, name: str = ""):
        config.setup()
        self.name: str = config.get_player_name() or name
        self.health: int = config.get_player_health() | 100
        self.attack: int = random.randint(config.get_attack_range()[0], config.get_attack_range()[1]) | random.randint(16, 20)
        self.heal: int = random.randint(16, 20) # | range in config
        self.powers: dict[str, int] = {"Freeze" : 6, "Burn": 8}
        self.death_message: list[str] = ["The Hero Has fallen"]
        self.location: str = None

class Monster():
    def __init__(self):
        self.name: dict[str, str] = {"base_location": "Drax"} # | name from location
        self.health: int = 100 # | health in config
        self.attack: int = random.randint(16, 20) # | range in config
        self.heal: int = random.randint(16, 20) # | range in config
        self.death_message: list[str] = [f"You have slaughtered {self.name} and conquered the terrain."]


