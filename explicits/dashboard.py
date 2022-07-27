
from rich.align import Align
from textual.layouts.grid import GridLayout
from .config import Config
from textual.widget import Panel, Widget
from .box import Box

async def dashboard() -> GridLayout:
    # def render(self) -> Panel:
    #     data = f"""name = {Config().get_player_name()}\nhealth = {Config().get_player_health()}
    #     """
    #     return Panel(Align.center(data))

    grid = DockView().dock_grid()

    grid.add_column(fraction=1, name="left", min_size=20)
    grid.add_column(size=30, name="center")
    grid.add_column(fraction=1, name="right")
    grid.add_row(fraction=1, name="top", min_size=2)
    grid.add_row(fraction=2, name="middle")
    grid.add_row(fraction=1, name="bottom")
    grid.add_areas(
        area1="left,top",
        area2="center,middle",
        area3="left-start|right-end,bottom",
        area4="right,top-start|middle-end",
    )

    grid.place(
        area1=Box(name="area1"),
        area2=Box(name="area2"),
        area3=Box(name="area3"),
        area4=Box(name="area4"),
    )
    return grid
