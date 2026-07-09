# LibSys

A modern and reliable library management system built with C++ and Qt.

## Overview

LibSys is a desktop application for managing library operations including book inventory, reader records, book lending/returns, fine tracking, and librarian management. The system uses various data structures and design patterns to ensure efficient and maintainable operations.

## Features

- **Book Management** — add, remove, search, and browse books stored in a binary search tree
- **Reader Management** — add, remove, and search readers stored in a hash table
- **Lending & Returns** — check out and check in books with entry records stored in a doubly linked list
- **Fine Management** — impose and pay fines on overdue or damaged books using the Decorator pattern
- **Publisher Management** — manage publisher information using the Builder pattern
- **Librarian Management** — track librarian details stored in a hash table
- **Observer Pattern** — UI updates are triggered automatically via the Observer pattern when entries change
- **Factory Pattern** — dialog creation is handled through a factory for centralized UI management

## Design Patterns Used

| Pattern | Location | Purpose |
|---|---|---|
| **Composite** | `IEntryComponent`, `EntriesL` | Uniform handling of individual entries and entry collections |
| **Decorator** | `FineDecorator`, `IEntryComponent` | Attach fine information to lending entries without modifying the base entry |
| **Builder** | `PublisherBuilder` | Step-by-step construction of `Publisher` objects |
| **Observer** | `EntryObserver`, `EntryObserver.h`, `EntriesL`, `MainWindowObserver` | Automatic UI refresh when entry data changes |
| **Strategy** | Sorting in `EntriesL` | Encapsulate sorting algorithms for entry lists |
| **Factory** | `DialogFactory`, `dialogfactory.h` | Centralized dialog creation |

## Data Structures

- **Binary Search Tree** — `BooksT` for book storage and lookup by cipher
- **Hash Table (Open Addressing)** — `ReadersHT`, `LibrariansHT`, `PublishersHT` for readers, librarians, and publishers
- **Doubly Linked List** — `EntriesL` for lending/return records
- **Dynamic Array (Vector)** — `FinesL` for fine records

## Tech Stack

- **Language:** C++17
- **Framework:** Qt 6 (Widgets)
- **Build System:** qmake
- **Compiler:** MinGW 64-bit

## Build Instructions

### Prerequisites
- Qt 6.7.3+ with MinGW 64-bit
- C++17 compatible compiler

### Build
```bash
qmake LibSys.pro
make
# or open LibSys.pro in Qt Creator and build
```

## Project Structure

```
├── include/               # Header files
│   ├── BooksT.h           # Binary search tree for books
│   ├── ReadersHT.h        # Hash table for readers
│   ├── EntriesL.h         # Doubly linked list for lending entries
│   ├── LibrariansHT.h     # Hash table for librarians
│   ├── PublishersHT.h     # Hash table for publishers
│   ├── FinesL.h           # Fine records list
│   ├── IEntryComponent.h  # Component interface (Composite pattern)
│   ├── FineDecorator.h    # Decorator for fines on entries
│   ├── PublisherBuilder.h # Builder for Publisher objects
│   ├── EntryObserver.h    # Observer interface
│   ├── MainWindowObserver.h # UI observer
│   ├── dialogfactory.h    # Factory for dialogs
│   ├── *.h                # Dialog headers
│   └── Tests*.h           # Unit tests (hash table, list, tree)
├── forms/                 # Qt Designer form files
│   ├── mainwindow.ui
│   ├── addbookdialog.ui
│   ├── addentrydialog.ui
│   ├── addreaderdialog.ui
│   ├── closeentrydialog.ui
│   ├── FineDialog.ui
│   ├── removebookdialog.ui
│   ├── removereaderdialog.ui
│   ├── searchbookdialog.ui
│   └── searchreaderdialog.ui
├── src/                   # Source files
│   ├── BooksT.cpp
│   ├── ReadersHT.cpp
│   ├── EntriesL.cpp
│   ├── LibrariansHT.cpp
│   ├── PublishersHT.cpp
│   ├── FinesL.cpp
│   ├── dialogfactory.cpp
│   ├── main.cpp           # Application entry point
│   ├── mainwindow.cpp
│   ├── FineDialog.cpp
│   └── *.cpp              # Dialog implementations
├── LibSys.pro             # qmake project file
└── README.md
```
