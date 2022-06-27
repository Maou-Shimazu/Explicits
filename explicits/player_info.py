from __future__ import annotations
import random
 # TODO: write funcs to retrieve values from config file(s)

class Player():
    def __init__(self, name: str):
        self.name: str = name # | name in config 
        self.health: int = 100 # | health in config
        self.attack: int = random.randint(16, 20) # | range in config
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


