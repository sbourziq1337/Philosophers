[![ascii-text-art](https://private-user-images.githubusercontent.com/39954629/293942724-e65a4d3e-10a2-44b6-bf27-f79c71b4f7e6.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzU2NjYwNDMsIm5iZiI6MTczNTY2NTc0MywicGF0aCI6Ii8zOTk1NDYyOS8yOTM5NDI3MjQtZTY1YTRkM2UtMTBhMi00NGI2LWJmMjctZjc5YzcxYjRmN2U2LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDEyMzElMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQxMjMxVDE3MjIyM1omWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWE5MDM1NWU3NTg5NGE4M2QzYTAyOTYwZDI1ZTRkMzRmYzYxYmUxZmVmYWNlMDc2Yjk0YzRmZWZhOWUxNjJiOGYmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.q4HpTEjQvM8h18207InxOIzTxwfL2oIGF-cns8t0AVw)](https://private-user-images.githubusercontent.com/39954629/293942724-e65a4d3e-10a2-44b6-bf27-f79c71b4f7e6.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzU2NjYwNDMsIm5iZiI6MTczNTY2NTc0MywicGF0aCI6Ii8zOTk1NDYyOS8yOTM5NDI3MjQtZTY1YTRkM2UtMTBhMi00NGI2LWJmMjctZjc5YzcxYjRmN2U2LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDEyMzElMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQxMjMxVDE3MjIyM1omWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWE5MDM1NWU3NTg5NGE4M2QzYTAyOTYwZDI1ZTRkMzRmYzYxYmUxZmVmYWNlMDc2Yjk0YzRmZWZhOWUxNjJiOGYmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.q4HpTEjQvM8h18207InxOIzTxwfL2oIGF-cns8t0AVw)

# Philosophers Project
-----------------------------------------

## Description
--------------------------------------

This project simulates a classic problem in computer science, _the dining philosophers problem_. It involves philosophers sitting at a table, doing one of three things: eating, thinking, or sleeping. While eating, they need two forks, which are shared with neighbors.

_The Dining Philosophers problem_ is a classic puzzle in computer science, often used to illustrate the challenges of resource allocation and synchronization in concurrent programming. At first glance, it might seem like a quirky thought experiment, but it mirrors real-world scenarios in computing quite closely



![](https://miro.medium.com/v2/resize:fit:1130/1*SdI7qwsNa05IkyiMXlAmPg.png)
## The Scenario
---------------------

Imagine a round table with several philosophers (threads) sitting around it. Each philosopher wants to eat (access a critical resource like a fork), but there are only a limited number of forks (resources) available.

[![Screen Shot 2024-01-05 at 5 39 38 PM](https://private-user-images.githubusercontent.com/39954629/299379330-ba9d0d13-ce07-4a27-b043-060bcf3cd0ae.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzU2NjYwNDMsIm5iZiI6MTczNTY2NTc0MywicGF0aCI6Ii8zOTk1NDYyOS8yOTkzNzkzMzAtYmE5ZDBkMTMtY2UwNy00YTI3LWIwNDMtMDYwYmNmM2NkMGFlLmpwZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDEyMzElMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQxMjMxVDE3MjIyM1omWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWI4NDgxNmQ5YTQ4YWUxNGJjYTU2NmY0MTVjYWIxZGMzZGM0NzczYzYxNmRhYTM3MzIxZDA3ZjU1OTkzNTUzZjgmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.7ocDoqOUybyOV1D0IG_D_3vwdY-5kkRUcI6v-4kyzuE)](https://private-user-images.githubusercontent.com/39954629/299379330-ba9d0d13-ce07-4a27-b043-060bcf3cd0ae.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzU2NjYwNDMsIm5iZiI6MTczNTY2NTc0MywicGF0aCI6Ii8zOTk1NDYyOS8yOTkzNzkzMzAtYmE5ZDBkMTMtY2UwNy00YTI3LWIwNDMtMDYwYmNmM2NkMGFlLmpwZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDEyMzElMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQxMjMxVDE3MjIyM1omWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWI4NDgxNmQ5YTQ4YWUxNGJjYTU2NmY0MTVjYWIxZGMzZGM0NzczYzYxNmRhYTM3MzIxZDA3ZjU1OTkzNTUzZjgmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.7ocDoqOUybyOV1D0IG_D_3vwdY-5kkRUcI6v-4kyzuE)

- **Five Philosophers:** They alternate between thinking and eating.
- **Five Forks:** One between each philosopher.
- **The Problem:** To eat, a philosopher needs both forks on either side.

## The Challenge
-----------------------------------------

The catch is simple yet complex. If every philosopher simultaneously picks up the left fork, they all wait for the right fork indefinitely – a _deadlock_. This situation perfectly mimics real-world scenarios in computing where processes wait indefinitely for _resources_, leading to system freezes.

#### Parameters
---------------------------
The program accepts the following arguments:

1. `number_of_philosophers`: Number of philosophers seated at the table.
    
2. `time_to_die`: Time (in milliseconds) a philosopher can survive without eating after their last meal or the start of the simulation.
    
3. `time_to_eat`: Time (in milliseconds) required for a philosopher to finish eating.
    
4. `time_to_sleep`: Time (in milliseconds) a philosopher spends sleeping.
    
5. `[number_of_times_each_philosopher_must_eat]` (optional): The simulation ends if all philosophers have eaten this many times. If not specified, the simulation continues until a philosopher dies.
    

#### Output Format
--------------------------

The program prints messages for each philosopher's actions:

```
[timestamp_in_ms] [X] has taken a fork
[timestamp_in_ms] [X] is eating
[timestamp_in_ms] [X] is sleeping
[timestamp_in_ms] [X] is thinking
[timestamp_in_ms] [X] died
```

---

### Mandatory Part: Threads and Mutexes

In the mandatory part, the simulation is implemented using threads and mutexes:

- Each philosopher is represented by a **thread**.
    
- Each fork is represented by a **mutex**.
    
- Philosophers must acquire the forks to their immediate left and right to eat.
    

#### Usage

1. Clone the repository:
    
    ```
    git clone https://github.com/sbourziq1337/Philosophers.git
    ```
    
2. Navigate to the mandatory part directory:
    
    ```
    cd philosophers/philo
    ```
    
3. Compile the project:
    
    ```
    make
    ```
    
4. Run the program:
    
    ```
    ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philo_must_eat]
    ```
    
    Example:
    
    ```
    ./philo 4 800 200 200 5
    ```
    
    - In this example:
        
        - 4 philosophers are seated.
            
        - Each philosopher dies if they don’t eat within 800ms.
            
        - Eating and sleeping each take 200ms.
            
        - The simulation stops after each philosopher has eaten 5 times.
### Key Insights

---

This project serves as a practical demonstration of concepts in concurrent programming, including:

1. **Synchronization:** Using mutexes to manage shared resources (forks) prevents race conditions.
2. **Deadlock Avoidance:** By designing strategies like prioritizing fork acquisition order, you can prevent deadlocks.
3. **Starvation Prevention:** Ensuring that all philosophers get fair access to resources is crucial for a balanced simulation.

By tackling the dining philosophers problem, you explore the fundamental challenges faced in multi-threaded programming and the techniques used to resolve them effectively.
