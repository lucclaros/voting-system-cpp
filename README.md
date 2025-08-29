# voting-system-cpp
Voting System Simulation: Parties and Students

# Guirnalda Voting System

This C++ program simulates a voting system with students (`ALUMNO`) and parties (`PARTIDO`). Each student belongs to a party, and the program organizes and manages the data using linked lists.

## Classes

### `ALUMNO`
- Represents a student.
- Attributes:
  - `NOM` : name of the student.
  - `SIG` : pointer to the next student in the list.
- Constructor and destructor manage memory and display messages when creating or deleting students.

### `PARTIDO`
- Represents a party.
- Attributes:
  - `NOM` : name of the party.
  - `PALUM` : pointer to the first student of the party.
  - `SIG` : pointer to the next party in the list.
- Constructor links a student as the first member of the party.
- Destructor should remove all associated students.

### `GUIRNALDA`
- Represents the overall system of parties and students.
- Attributes:
  - `INICIO` : pointer to the first party.
- Methods:
  - `ARREGLATE(char *)` : Adds a student to the correct party or creates a new party if it does not exist.
  - `MIRAR()` : Prints all parties and their students.
  - `TRUCHO(char *)` : Checks if a student has already voted.
  - `BUSCAR(char *)` : Finds a party by name.

## How it works
1. Students are generated randomly with `GENERARNOM()`.
2. Each student is assigned to a party using `ARREGLATE()`.
3. Duplicate votes are ignored using `TRUCHO()`.
4. The program displays all parties and their students.

## Compilation
Use a C++ compiler, for example with g++:

```bash
g++ guirnalda.cpp -o guirnalda
./guirnalda
