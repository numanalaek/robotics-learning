from enum import Enum

class RobotState(Enum):
    READY = 1
    LOW_BATTERY = 2
    FAULT = 3

class Direction(Enum):
    NORTH = 0
    EAST = 1
    SOUTH = 2
    WEST = 3

class Environment:
    def __init__(self):
        self.obstacles = [(5, 5), (3, 7), (-2, 1)]

class Robot:
    DIRECTIONS = [Direction.NORTH, Direction.EAST, Direction.SOUTH, Direction.WEST]
    DIRECTION_VECTORS = {
        Direction.NORTH: (0, 1),
        Direction.EAST: (1, 0),
        Direction.SOUTH: (0, -1),
        Direction.WEST: (-1, 0),
    }

    def __init__(self, name, environment):
        self.name = name
        self.x = 0
        self.y = 0
        self.battery = 100
        self.direction = Direction.NORTH
        self.state = RobotState.READY
        self.env = environment

    def status(self):
        print("\n=== Robot Status ===")
        print(f"Robot   : {self.name}")
        print(f"State   : {self.state.name}")
        print(f"Battery : {self.battery}%")
        print(f"Posisi  : ({self.x}, {self.y})")
        print(f"Arah    : {self.direction.name}")

    def can_move(self):
        return self.state != RobotState.FAULT and self.battery > 0

    def consume_battery(self):
        self.battery -= 1
        if self.battery <= 0:
            self.state = RobotState.FAULT
            print("Battery empty!")
        elif self.battery < 20:
            self.state = RobotState.LOW_BATTERY
        else:
            self.state = RobotState.READY

    def charge(self):
        self.battery = 100
        self.state = RobotState.READY

    def get_direction_vector(self):
        return Robot.DIRECTION_VECTORS[self.direction]

    def turn_left(self):
        if not self.can_move():
            return
        current_idx = self.direction.value
        self.direction = Robot.DIRECTIONS[(current_idx - 1) % 4]
        self.consume_battery()

    def turn_right(self):
        if not self.can_move():
            return
        current_idx = self.direction.value
        self.direction = Robot.DIRECTIONS[(current_idx + 1) % 4]
        self.consume_battery()

    def move_forward(self):
        if not self.can_move():
            return
        dx, dy = self.get_direction_vector()
        nx, ny = self.x + dx, self.y + dy
        if (nx, ny) in self.env.obstacles:
            print("Obstacle detected, stop movement")
            return
        self.x, self.y = nx, ny
        self.consume_battery()

    def move_backward(self):
        if not self.can_move():
            return
        dx, dy = self.get_direction_vector()
        nx, ny = self.x - dx, self.y - dy
        if (nx, ny) in self.env.obstacles:
            print("Obstacle detected, stop movement")
            return
        self.x, self.y = nx, ny
        self.consume_battery()

warehouse = Environment()
robot = Robot("nuin-amr-01", warehouse)

while True:
    robot.status()
    cmd = input("\nPerintah [w/s/q] | belok [a/d] | charge : ").strip().lower()

    if cmd == "w":
        robot.move_forward()
    elif cmd == "s":
        robot.move_backward()
    elif cmd == "a":
        robot.turn_left()
    elif cmd == "d":
        robot.turn_right()
    elif cmd == "charge":
        robot.charge()
    elif cmd == "q":
        print("Program selesai.")
        break
    else:
        print("Perintah tidak dikenal!")
