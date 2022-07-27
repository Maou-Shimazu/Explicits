from textual.app import App
from explicits.main_window import Main_Window
from textual import events
from explicits.header import Header
from explicits.dashboard import dashboard
from explicits.footer import Footer
from explicits.box import Box
from textual.layouts.grid import GridLayout

class Main(App):
    """Main Application to run and manage events ran by the user."""
    async def on_mount(self) -> None:
        # await self.view.dock()
        await self.view.dock(Header(), edge="top")
        # await self.view.dock(dashboard(), size=20, edge="left", name="dashboard")
        await self.view.dock(Footer(), edge="bottom")
        # await self.view.dock(Box(name="Stats", data="name = Maou", height=20), name="Stats", size=20)
        self.grid.place("words")

    async def on_load(self, event: events.Load) -> None:
        await self.bind("q", "quit", "Quit")

    async def _make_grid(self, grid: GridLayout) -> None:
        grid.add_row("sep", size=1)
        grid.add_row("a", size=3)
        grid.add_row("sep0", size=1)
        grid.add_row("b")
        grid.add_row("sep1", size=1)
        grid.add_row("bar", size=1)

        grid.add_column("sep0", size=1)
        grid.add_column("0", fraction=20)
        grid.add_column("sep1", size=1)
        grid.add_column("padding", size=1)
        grid.add_column("sep2", size=1)
        grid.add_column("1", fraction=80)
        grid.add_column("sep3", size=1)

    async def setup_grid(self) -> None:
        """
        Handle grid placing
        """

        self.grid = await self.view.dock_grid()
        await self._make_grid(self.grid)

    
Main.run(title="Explicits", log="explicits.log")
