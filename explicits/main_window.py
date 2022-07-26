
from textual.widget import Widget
from textual.widget import Reactive
from textual.widget import Panel
from rich.align import Align

class Main_Window(Widget):   
    mouse_over = Reactive(False)

    def render(self) -> Panel:
        return Panel(Align.center("[b]Dashboard[/b]"))

    def on_enter(self) -> None:
        self.mouse_over = True

    def on_leave(self) -> None:
        self.mouse_over = False
