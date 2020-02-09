#ifndef PATTERNS_COMPOSITION__H
#define PATTERNS_COMPOSITION__H
#include <string>


namespace pattern {
    constexpr size_t MAX_FILE_SIZE = 1000*1024;

    class ICompBase {
    public:
        virtual void show() = 0;

        virtual std::string get() { return m_output; };

        // Default constructor
        ICompBase() = default;

        virtual ~ICompBase() = default;

        ICompBase(const ICompBase &) = delete;

        ICompBase &operator=(const ICompBase &) = delete;

    protected:
        std::string m_output;
    };


    class FileHandler : public ICompBase {
    public:
        explicit FileHandler(const std::string &);

        void show() override;

        ~FileHandler() override = default;
    };

    class DotFilesNotation: ICompBase {

    };

}
#endif // PATTERNS_COMPOSITION__H