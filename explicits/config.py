from appdirs import *
from log import logger
import os

class Config():
    def __init__(self): 
        self.dir: AppDirs = AppDirs("Explicits")
        self.config: str = self.dir.user_config_dir + "/config.toml"

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

Config().setup()

