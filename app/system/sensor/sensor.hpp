/*---------------------------------------------------------------- 
xxx版权所有。
作者：
时间：2020.7.10
----------------------------------------------------------------*/

/*
	调用方法：
	Sensor *pSensor = Sensor::getInstance();
	pSensor->setFps(30);
*/

#pragma once

#include "mi_sensor.h"

class Sensor{
public:
	static Sensor *getInstance(){
		static Sensor sensor;
		return &sensor;
	}

	int enable();									// 启用sensor
	int disable();									// 禁用sensor

	int getFps(MI_U32 *u32Fps);						// 获取帧率
	int setFps(MI_U32 u32Fps);						// 设置帧率

	int getPadInfo(MI_SNR_PADID ePADId, MI_SNR_PADInfo_t *pstPadInfo);				// 获取sensor 设备信息
	int getPlaneInfo(MI_SNR_PADID ePADId, MI_SNR_PlaneInfo_t *pstPlaneInfo);	// 获取sensor 通道信息
	
private:
	Sensor();
	~Sensor();
	Sensor(const Sensor&);
	Sensor& operator=(const Sensor&);

	bool bEnable = false;
	MI_U32 u32ResCnt = 0;
	const static MI_U32 u32DefFps = 30;
	const static MI_U32 u32PlaneID = 0;
	const static MI_BOOL bEnableHDR = false;
	//const static MI_SNR_PADID ePADId= E_MI_SNR_PAD_ID_0;	// 在tiramisu 中找不到定义
	const static MI_SNR_PADID ePADId= 0;
};

