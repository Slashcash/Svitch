#ifndef _OPRESULT_HPP_
#define _OPRESULT_HPP_

#include <ostream>
#include <sstream>

enum Error { //all the things that can go wrong in this software
    ERR_OUT_OF_MEMORY = 1,
    ERR_INITIALIZE_NS,
    ERR_NS_NOT_FOUND,
    ERR_GET_APP_CONTROLDATA,
    ERR_OUTSIZE_TOO_SMALL,
    ERR_OPEN_STREAM,
    ERR_INVALID_SAVEHEADER,
    ERR_OPEN_ITERATOR,
    ERR_READ_ITERATOR,
    ERR_TOO_MANY_SAVEFILES,
    ERR_INITIALIZE_ACC,
    ERR_GET_USERID,
    ERR_ACCOUNT_NOT_LOGGED,
    ERR_MOUNT_SAVEDATA,
    ERR_MOUNT_DEVICE,
    ERR_UNMOUNT_SAVEDATA,
    ERR_INIT_ARCHIVE,
    ERR_WRITE_ARCHIVE_HEADER,
    ERR_CREATE_ARCHIVE_DIRECTORY,
    ERR_WRITE_ARCHIVE_FILE,
    ERR_FINALIZE_ARCHIVE,
    ERR_WRITE_FILE,
    ERR_CREATE_THREAD,
    ERR_START_THREAD,
    ERR_FREETYPE_NOT_INITIALIZED,
    ERR_LOAD_FONT_FACE,
    ERR_FONT_NOT_LOADED,
    ERR_SET_FONT_SIZE,
    ERR_PARSE_FILE
};

class OPResult {
    private:
        unsigned int err_number;
        unsigned int err_number_libnx;

    public:
        static const unsigned int SUCCESS = 0;

        OPResult(const unsigned int theErrNumber = SUCCESS, const unsigned int theLibNXErrNumber = SUCCESS);

        unsigned int getErrorNumber() const { return err_number; }
        unsigned int getLibNXErrorNumber() const { return err_number_libnx; }
        std::string str() const;

        void setErrorNumber(const unsigned int theErrorNumber) { err_number = theErrorNumber; }
        void setLibNXErrorNumber(const unsigned int theLibNXErrorNumber) { err_number_libnx = theLibNXErrorNumber; }

        operator bool() { return !err_number; }


};

#endif // _OPRESULT_HPP_
