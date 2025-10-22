// PublisherBuilder.h
#ifndef PUBLISHERBUILDER_H
#define PUBLISHERBUILDER_H

#include "Publisher.h"
#include <string>

class PublisherBuilder {
public:
    PublisherBuilder& setName(const std::string& name) {
        publisher.name = name;
        return *this;
    }

    PublisherBuilder& setAddress(const std::string& address) {
        publisher.address = address;
        return *this;
    }

    PublisherBuilder& setContactInfo(const std::string& contactInfo) {
        publisher.contactInfo = contactInfo;
        return *this;
    }

    Publisher* build() {
        return new Publisher{publisher.name, publisher.address, publisher.contactInfo};
    }

private:
    Publisher publisher;
};

#endif // PUBLISHERBUILDER_H
