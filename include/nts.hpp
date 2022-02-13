/*
** EPITECH PROJECT, 2020
** nts
** File description:
** nts
*/

#ifndef NTS_HPP_
#define NTS_HPP_

#include "nts_error.hpp"

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual bool operator<(const IComponent &) = 0;

        public:
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void setState(std::size_t pin, nts::Tristate state) = 0;
            virtual void dump() const = 0;
            virtual std::string getValue() const = 0;
            virtual std::string getType() const = 0;
            virtual nts::Tristate getState(std::size_t pin) const = 0;
            virtual bool isLinked(size_t pin) const = 0;
            virtual void reset() = 0;
            virtual void changeState() = 0;
            virtual std::vector<std::pair<nts::IComponent *, std::size_t>>getLinks(std::size_t) = 0;
    };

    typedef std::unique_ptr<nts::IComponent> ptrComponent;

    class nbSimulate {
        public:
            static std::size_t nb_simulate;
    };

    class AComponent : public IComponent {
        public:
            explicit AComponent(std::string);
            bool operator<(const IComponent &) final;

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void setState(std::size_t pin, nts::Tristate state) override;
            std::string getValue() const override;
            std::string getType() const override;
            nts::Tristate getState(std::size_t pin) const override;
            bool isLinked(size_t pin) const final;
            void reset() override;
            void changeState() override;
            std::vector<std::pair<nts::IComponent *, std::size_t>>getLinks(std::size_t) override;

        protected:
            std::map<int, nts::Tristate> _pinsSt;
            std::map<int, std::pair<nts::IComponent *, int>> _pinsLk;
            std::string _value;
    };
}

#endif