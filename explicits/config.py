from appdirs import *
from .log import logger
import os
import toml

class Config():
    def __init__(self): 
        self.dir: AppDirs = AppDirs("Explicits")
        self.config: str = self.dir.user_config_dir + "/config.toml"
        self.content: dict = toml.load(self.config)

    def setup(self):
        logger.info("Setting Up Explicits Configuration.")
        if not os.path.isdir(self.dir.user_config_dir):
            os.mkdir(self.dir.user_config_dir)
            with open(self.config, "x") as config:
                logger.info(f"{self.config} Created.")
                config.close()
            logger.info("Config Created.")
        else:
            logger.info("Configuration Loaded")

    def locations(self) -> str:
        print(self.dir.user_config_dir)
        print(self.config)
    
    def get_player_name(self) -> str:
        return self.content["player"]["name"]
    
    def set_player_name(self) -> str:
        pass

    def get_player_health(self) -> str:
        return self.content["player"]["health"]

    def set_player_health(self) -> None:
        pass

    def get_attack_range(self) -> list[str, str]:
        return self.content["player"]["attack"]

    def set_attack_range(self) -> None:
        pass

    def get_heal_range(self) -> list[str, str]:
        return self.content["player"]["heal"]

    def set_heal_range(self) -> None:
        pass
    
    def get_powers(self) -> dict[str, int]:
        return self.content["player"]["powers"]
    
    def set_powers(self) -> None:
        pass
    
    def get_location(self) -> str:
        return self.content["player"]["location"]
    
    def set_location(self) -> None:
        pass

Config().get_attack_range()

