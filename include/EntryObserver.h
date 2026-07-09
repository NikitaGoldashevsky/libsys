#ifndef ENTRYOBSERVER_H
#define ENTRYOBSERVER_H

class EntryObserver {
public:
    virtual ~EntryObserver() = default;
    virtual void update() = 0; // Метод, который вызывается при добавлении записи
};

#endif // ENTRYOBSERVER_H
