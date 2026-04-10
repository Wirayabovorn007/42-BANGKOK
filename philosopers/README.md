*This project has been created as part of the 42 curriculum by wiboonpr.*

# Philosophers

## Description
This project is an implementation of the classic **Dining Philosophers problem**, designed to teach the fundamentals of multithreading, process synchronization, and resource sharing. 

The simulation involves a set number of philosophers sitting around a circular table with a large bowl of spaghetti in the middle. They alternate between three states: **eating, sleeping, and thinking**. 
To eat, a philosopher must successfully pick up two forks (one on their left, one on their right). 

The primary challenge of this project is to create an algorithm that prevents **deadlocks** (where everyone is stuck waiting for a fork) and **data races** (where multiple threads corrupt shared memory), ensuring that no philosopher starves to death.

### Key Technical Concepts:
* **Multithreading:** Each philosopher is represented by an individual POSIX thread `pthread_create`.
* **Mutexes:** Each fork is protected by a mutex `pthread_mutex_t` to ensure only one philosopher can hold it at a time. Mutexes are also used to protect shared data like timestamps and state flags.
* **Data Race Prevention:** Strict synchronization using mutex locks to prevent undefined behavior when reading/writing to shared variables.
* **High-Precision Timing:** Custom sleep and time-checking algorithms using `gettimeofday` to monitor philosopher survival with millisecond accuracy.

---

## Instructions

### Compilation
The project includes a `Makefile` that compiles the source files with the required flags.
To compile the program, simply run:
```bash
make
```

This will generate the philo executable. You can also use make clean to remove object files, make fclean to remove both object files and the executable, and make re to recompile from scratch.

### Execution
Run the program with the following arguments:
```
./philo number_of_philosophers time_to_die time_to_eat time_to_slee [number_of_times_each_philosopher_must_eat]
```

- number_of_philosophers: The number of philosophers (and forks) at the table.
- time_to_die (ms): If a philosopher hasn't started eating within this time after their last meal (or the start of the simulation), they die.

- time_to_eat (ms): The time it takes for a philosopher to eat (requires holding 2 forks).

- time_to_sleep (ms): The time a philosopher spends sleeping after dropping their forks.

- number_of_times_each_philosopher_must_eat (Optional): The simulation stops if all philosophers eat at least this many times. If not specified, the simulation runs until a philosopher dies.

## Usage Examples

**Infinite Survival:** No one dies, stop with Ctrl+C
```
./philo 4 410 200 200
```

**Guaranteed Death:** Philosopher 1 will die because they don't have enough time to wait for the forks.
```
./philo 4 310 200 100
```

**Meal Limit:** Simulation ends once everyone has eaten 10 times.
```
./philo 4 410 200 200 10
```

## Resources
### Theory
- [Philosopher 42 guide on Medium](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2)
- [Race condition](https://en.wikipedia.org/wiki/Race_condition)
- [Race condition (in thai)](https://medium.com/scb-techx/race-condition-%E0%B8%AA%E0%B8%B4%E0%B9%88%E0%B8%87%E0%B8%97%E0%B8%B5%E0%B9%88-developer-%E0%B8%97%E0%B8%B8%E0%B8%81%E0%B8%84%E0%B8%99%E0%B8%95%E0%B9%89%E0%B8%AD%E0%B8%87%E0%B8%A3%E0%B8%B9%E0%B9%89-85c05e1deffb)

## AI Usage
AI was used strictly as a tutor and debugging assistant. Specifically, AI was used for:
- Discussing the theoretical differences between data races and deadlocks.

- Explaining the behavior of the OS CPU scheduler and the inaccuracies of the standard usleep function.

- Reviewing multithreading logic to identify potential race conditions in shared variable reads/writes.

- Simulating peer-evaluation questions to practice explaining the core concepts.
