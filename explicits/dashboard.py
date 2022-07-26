
from rich.align import Align
from config import Config
from textual.widget import Panel, Widget

class Dashboard(Widget):
    def render(self) -> Panel:
        data = f"""name = {Config().get_player_name()}\nhealth = {Config().get_player_health()}
        """
        return Panel(Align.center(data))

