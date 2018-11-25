#ifndef SAPPHIRE_DBMANAGER
#define SAPPHIRE_DBMANAGER
#include <string>
#include <stdint.h>
#include <memory>

namespace Mysql 
{
  class Connection;
}

enum class Mode
{
  INIT,
  LIQUIDATE,
  UPDATE,
  CHECK,
  CLEAN_CHARS
};

class DbManager
{
  public:
    DbManager( const std::string& host, const std::string& database, const std::string& user, const std::string& pw, uint16_t port );
    
    void setMode( Mode mode );
    Mode getMode() const;

    bool connect();
    bool selectSchema();

    virtual ~DbManager();

    const std::string& getLastError();

  private:
    std::string m_host;
    std::string m_database;
    std::string m_user;
    std::string m_password;
    uint16_t m_port;
    std::shared_ptr< Mysql::Connection > m_pConnection;
    std::string m_lastError;
    Mode m_mode;
};



#endif