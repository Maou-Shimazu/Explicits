import pytermgui as ptg
from .log import logger

class Dashboard():
    def __init__(self):
        logger.info("Dashboard initiated")
        with ptg.WindowManager() as wm:
            wm.add(
                    ptg.Window(
                    "[title]Dashboard",
                    "",
                    {"[body] stuff" : ["content"]},
                    ["Exit", lambda *_: wm.stop()]
                        ).center()
                    )
