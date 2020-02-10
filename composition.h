#ifndef PATTERNS_COMPOSITION__H
#define PATTERNS_COMPOSITION__H
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <memory>

namespace pattern {
    constexpr size_t MAX_FILE_SIZE = 1000*1024;

    class ICompBase {
    public:
        virtual void show(std::ostream &out=std::cout) const = 0;
        friend std::ostream& operator<< (std::ostream& stream, const ICompBase& base);

        // Default constructor
        ICompBase() = default;

        virtual ~ICompBase() = default;

        ICompBase(const ICompBase &) = delete;

        ICompBase &operator=(const ICompBase &) = delete;
    };

    class FileHandler : public ICompBase {
    public:
        explicit FileHandler(const std::string &);

        void show(std::ostream &out=std::cout) const override;

        ~FileHandler() override = default;

    private:
        std::string m_output;
    };

    class DotFilesNotation: public ICompBase {
    public:
        void show(std::ostream &out=std::cout) const override;

        void add(ICompBase*);

    private:
        std::list<std::unique_ptr<ICompBase>> children;

    };

}
#endif // PATTERNS_COMPOSITION__H