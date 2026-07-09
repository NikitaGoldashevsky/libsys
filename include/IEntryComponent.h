#ifndef IENTRYCOMPONENT_H
#define IENTRYCOMPONENT_H
#include <string>

class IEntryComponent {
public:
    virtual ~IEntryComponent() = default;

    // Основные данные записи
    virtual std::string getCard() const = 0;
    virtual std::string getCipher() const = 0;
    virtual std::string getIssueDate() const = 0;
    virtual std::string getReturnDate() const = 0;
    virtual std::string getLibrarianId() const = 0;

    // Виртуальный метод для отображения (опционально)
    virtual void print() const = 0;
};

#endif // IENTRYCOMPONENT_H
