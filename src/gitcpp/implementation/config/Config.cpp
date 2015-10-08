//
// Created by ekuch on 10/6/15.
//
#include "interface/FwdDecl.h"
#include "Config.h"
#include "implementation/ErrorUtil.h"
#include "git2/config.h"
#include "ConfigEntry.h"
#include "implementation/GitBuf.h"
#include "implementation/config/ConfigEntryIterator.h"

namespace gitcpp { namespace config {

Config::~Config()
{
    if (m_Handle)
    {
        git_config_free(m_Handle);
    }
}

IConfigEntryPtr Config::Entry(const std::string& sName)
{
    std::shared_ptr<ConfigEntry> ptrConfigEntry = std::make_shared<ConfigEntry>();
    gitcpp::ErrorUtil::ThrowOnError(git_config_get_entry(&ptrConfigEntry->m_Handle, m_Handle, sName.c_str()));
    return ptrConfigEntry;
}

int32_t Config::Int32(const std::string& sName)
{
    int32_t nValue;
    gitcpp::ErrorUtil::ThrowOnError(git_config_get_int32(&nValue, m_Handle, sName.c_str()));
    return nValue;
}
int64_t Config::Int64(const std::string& sName)
{
    int32_t nValue;
    gitcpp::ErrorUtil::ThrowOnError(git_config_get_int32(&nValue, m_Handle, sName.c_str()));
    return nValue;
}

bool Config::Bool(const std::string& sName)
{
    int nValue;
    gitcpp::ErrorUtil::ThrowOnError(git_config_get_bool(&nValue, m_Handle, sName.c_str()));
    return nValue == 1;
}
std::string Config::Path(const std::string& sName)
{
    GitBuf gitBuf;
    gitcpp::ErrorUtil::ThrowOnError(git_config_get_path(&gitBuf.m_Handle, m_Handle, sName.c_str()));
    return gitBuf.ToString();
}

std::string Config::String(const std::string& sName)
{
    const char* psValue;
    gitcpp::ErrorUtil::ThrowOnError(git_config_get_string(&psValue, m_Handle, sName.c_str()));
    return std::string(psValue);
}
void Config::Set(const std::string& sName, const int32_t nValue)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_set_int32(m_Handle, sName.c_str(), nValue));
}
void Config::Set(const std::string& sName, const int64_t nValue)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_set_int64(m_Handle, sName.c_str(), nValue));
}
void Config::Set(const std::string& sName, const bool bValue)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_set_bool(m_Handle, sName.c_str(), bValue));
}
void Config::Set(const std::string& sName, const std::string& sValue)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_set_string(m_Handle, sName.c_str(), sValue.c_str()));
}
void Config::Set(const std::string& sName, const std::string& sRegex, const std::string& sValue)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_set_multivar(m_Handle, sName.c_str(), sRegex.c_str(), sValue.c_str()));
}
void Config::Delete(const std::string& sName)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_delete_entry(m_Handle, sName.c_str()));
}
void Config::Delete(const std::string& sName, const std::string& sRegex)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_delete_multivar(m_Handle, sName.c_str(), sRegex.c_str()));
}

// TODO: Mapped entries

IConfigEntryIteratorPtr Config::MultivarIterator(const std::string& sName)
{
    auto ptrIterator = std::make_shared<ConfigEntryIterator>(nullptr);
    gitcpp::ErrorUtil::ThrowOnError(git_config_multivar_iterator_new(&ptrIterator->m_Handle, m_Handle, sName.c_str(), nullptr));
    return ptrIterator;
}
IConfigEntryIteratorPtr Config::MultivarIterator(const std::string& sName, const std::string& sRegex)
{
    auto ptrIterator = std::make_shared<ConfigEntryIterator>(nullptr);
    gitcpp::ErrorUtil::ThrowOnError(git_config_multivar_iterator_new(&ptrIterator->m_Handle, m_Handle, sName.c_str(), sRegex.c_str()));
    return ptrIterator;
}
IConfigEntryIteratorPtr Config::Iterator()
{
    auto ptrIterator = std::make_shared<ConfigEntryIterator>(nullptr);
    gitcpp::ErrorUtil::ThrowOnError(git_config_iterator_new(&ptrIterator->m_Handle, m_Handle));
    return ptrIterator;
}
IConfigEntryIteratorPtr Config::Iterator(const std::string& sRegex)
{
    auto ptrIterator = std::make_shared<ConfigEntryIterator>(nullptr);
    gitcpp::ErrorUtil::ThrowOnError(git_config_iterator_glob_new(&ptrIterator->m_Handle, m_Handle, sRegex.c_str()));
    return ptrIterator;
}

        int OnEntry(const git_config_entry * pEntry, void* pPayload)
        {
            IConfig::IForEachCallback * pCallback = static_cast<IConfig::IForEachCallback*>(pPayload);
            IConfigEntryPtr ptrEntry = std::make_shared<ConfigEntry>();
            return pCallback->DoWork(ptrEntry, pCallback);
        }

void Config::ForEachMultivar(IForEachCallback& callback, const std::string& sMultiVarName)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_get_multivar_foreach(m_Handle, sMultiVarName.c_str(), nullptr, OnEntry, &callback));
}
void Config::ForEachMultivar(IForEachCallback& callback, const std::string& sMultiVarName, const std::string& sRegex)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_get_multivar_foreach(m_Handle, sMultiVarName.c_str(), sRegex.c_str(), OnEntry, &callback));
}
void Config::ForEach(IForEachCallback& callback)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_foreach(m_Handle, OnEntry, &callback));
}
void Config::ForEach(IForEachCallback& callback, const std::string& sRegex)
{
    gitcpp::ErrorUtil::ThrowOnError(git_config_foreach_match(m_Handle, sRegex.c_str(), OnEntry, &callback));
}

IConfigPtr Config::Snapshot()
{
    auto configPtr = std::make_shared<Config>(nullptr);
    gitcpp::ErrorUtil::ThrowOnError(git_config_snapshot(&configPtr->m_Handle, m_Handle));
    return configPtr;
}
//TODO git_config_get_string_buf

}}