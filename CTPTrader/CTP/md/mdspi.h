#ifndef MD_SPI_H_
#define MD_SPI_H_
//#pragma once
//#include "api/trade/win/public/ThostFtdcMdApi.h"
#include "CTP/api/trade/win/public/ThostFtdcMdApi.h"

#include <cmysql_api.h>


class CtpMdSpi : public CThostFtdcMdSpi
{
public:
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo,
                            int nRequestID, bool bIsLast);
    virtual void OnFrontDisconnected(int nReason);

    virtual void OnHeartBeatWarning(int nTimeLapse);

    virtual void OnFrontConnected();

    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);


private:
    void ReqUserLogin();
    void SubscribeMarketData();
    bool IsErrorRspInfo(CThostFtdcRspInfoField* pRspInfo);
    CMySQL_Api* m_sql;

//  CtpMdSpi(CThostFtdcMdApi* api):pUserApi(api){};
//	///����Ӧ��
//	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo,
//		int nRequestID, bool bIsLast);

//	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ���������
//	///@param nReason ����ԭ��
//	///        0x1001 �����ʧ��
//	///        0x1002 ����дʧ��
//	///        0x2001 ����������ʱ
//	///        0x2002 ��������ʧ��
//	///        0x2003 �յ�������
//	virtual void OnFrontDisconnected(int nReason);
		
//	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
//	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
//	virtual void OnHeartBeatWarning(int nTimeLapse);

//	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
//	virtual void OnFrontConnected();
	
//	///��¼������Ӧ
//	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

//	///��������Ӧ��
//	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

//	///ȡ����������Ӧ��
//	virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

//	///�������֪ͨ
//	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

//public:
//	void ReqUserLogin(TThostFtdcBrokerIDType	appId,
//	        TThostFtdcUserIDType	userId,	TThostFtdcPasswordType	passwd);
//	void SubscribeMarketData(char* instIdList);
//	bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
//private:
//  CThostFtdcMdApi* pUserApi;
};

#endif