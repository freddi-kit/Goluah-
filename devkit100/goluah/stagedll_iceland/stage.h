﻿#pragma once

#include <windows.h>
#include <stdio.h>
#include <d3d8.h>
#include <d3dx8.h>
#include "gobjbase.h"

#define NUM_JIMEN_Z 15
#define NUM_JIMEN_X 15

/*!
 *	@brief ステージクラス
 */
class CStage : public CStageBase {
public:
  CStage(SDI_STAGEINFO2 *info);
  ~CStage();
  void InitializeStage();

protected:
  DWORD DrawBack();
  DWORD Action();

  void InitVrtx();
  void LoadTextures();

  void DrawWater();
  void DrawJimen();
  void DrawSky();

  //水面
  LPDIRECT3DTEXTURE8 ptex_water;
  MYVERTEX3D vb_water[4];

  //地面
  LPDIRECT3DVERTEXBUFFER8 vb_jimen[NUM_JIMEN_Z];

  //空
  LPDIRECT3DTEXTURE8 ptex_sky;
  LPDIRECT3DVERTEXBUFFER8 vb_sky;
};

#ifndef RELEASE
#define RELEASE(p)                                                                                           \
  if (p) {                                                                                                   \
    p->Release();                                                                                            \
    p = NULL;                                                                                                \
  }
#endif
