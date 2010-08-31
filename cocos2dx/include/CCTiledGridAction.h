/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __ACTION_CCTILEDGRID_ACTION_H__
#define __ACTION_CCTILEDGRID_ACTION_H__

#include "CCGridAction.h"

namespace cocos2d 
{
	/** CCShakyTiles3D action */
	class CCX_DLL CCShakyTiles3D : public CCTiledGrid3DAction
	{
	public:
		bool initWithRange(int nRange, bool bShakeZ, ccGridSize gridSize,
			ccTime duration);

		virtual NSObject* copyWithZone(NSZone* pZone);
		virtual void update(ccTime time);

	public:
		static CCShakyTiles3D* actionWithRange(int nRange, bool bShakeZ, ccGridSize gridSize,
			ccTime duration);

	protected:
		int m_nRandrange;
		bool m_bShakeZ;
	};

	/** CCShatteredTiles3D action */
	class CCX_DLL CCShatteredTiles3D : public CCTiledGrid3DAction
	{
	public:
        bool initWithRange(int nRange, bool bShatterZ, ccGridSize gridSize,
			ccTime duration);

		virtual NSObject* copyWithZone(NSZone* pZone);
		virtual void update(ccTime time);

	public:
		static CCShatteredTiles3D* actionWithRange(int nRange, bool bShatterZ, ccGridSize gridSize,
			ccTime duration);

	protected:
		int m_nRandrange;
		bool m_bOnce;
		bool m_bShatterZ;
	};

	struct Tile;
	/** CCShuffleTiles action
	 Shuffle the tiles in random order
	 */
	class CCX_DLL CCShuffleTiles : public CCTiledGrid3DAction
	{
	public:
		~CCShuffleTiles(void);
		bool initWithSeed(int s, ccGridSize gridSize, ccTime duration);
		void shuffle(int *pArray, int nLen);
		ccGridSize getDelta(ccGridSize pos);
		void placeTile(ccGridSize pos, Tile *t);

		virtual void startWithTarget(CCNode *pTarget);
		virtual void update(ccTime time);
		virtual NSObject* copyWithZone(NSZone* pZone);

	public:
		static CCShuffleTiles* actionWithSeed(int s, ccGridSize gridSize, ccTime duration);

	protected:
		int m_nSeed;
		int m_nTilesCount;
		int *m_pTilesOrder;
		void *m_pTiles;
	};

	/** CCFadeOutTRTiles action
	 Fades out the tiles in a Top-Right direction
	 */
	class CCX_DLL CCFadeOutTRTiles : public CCTiledGrid3DAction
	{
	public:
		virtual float testFunc(ccGridSize pos, ccTime time);
		void turnOnTile(ccGridSize pos);
		void turnOffTile(ccGridSize pos);
		virtual void transformTile(ccGridSize pos, float distance);
		virtual void update(ccTime time);

	public:
		static CCFadeOutTRTiles* actionWithSize(ccGridSize gridSize, ccTime time);
	};

	/** CCFadeOutBLTiles action.
	 Fades out the tiles in a Bottom-Left direction
	 */
	class CCX_DLL CCFadeOutBLTiles : public CCFadeOutTRTiles
	{
	public:
		virtual float testFunc(ccGridSize pos, ccTime time);

	public:
        static CCFadeOutBLTiles* actionWithSize(ccGridSize gridSize, ccTime time);
	};

	/** CCFadeOutUpTiles action.
	 Fades out the tiles in upwards direction
	 */
	class CCX_DLL CCFadeOutUpTiles : public CCFadeOutTRTiles
	{
	public:
		virtual float testFunc(ccGridSize pos, ccTime time);
		virtual void transformTile(ccGridSize pos, float distance);

	public:
        static CCFadeOutUpTiles* actionWithSize(ccGridSize gridSize, ccTime time);
	};

	/** CCFadeOutDownTiles action.
	 Fades out the tiles in downwards direction
	 */
	class CCX_DLL CCFadeOutDownTiles : public CCFadeOutUpTiles
	{
	public:
		virtual float testFunc(ccGridSize pos, ccTime time);

	public:
        static CCFadeOutDownTiles* actionWithSize(ccGridSize gridSize, ccTime time);
	};

	/** CCTurnOffTiles action.
	 Turn off the files in random order
	 */
	class CCX_DLL CCTurnOffTiles : public CCTiledGrid3DAction
	{
	public:
		~CCTurnOffTiles(void);
		bool initWithSeed(int s, ccGridSize gridSize, ccTime duration);
		void shuffle(int *pArray, int nLen);
		void turnOnTile(ccGridSize pos);
		void turnOffTile(ccGridSize pos);

		virtual NSObject* copyWithZone(NSZone* pZone);
		virtual void startWithTarget(CCNode *pTarget);
		virtual void update(ccTime time);

	public:
        static CCTurnOffTiles* actionWithSeed(int s, ccGridSize gridSize, ccTime duration);

	protected:
		int m_nSeed;
		int m_nTilesCount;
		int *m_pTilesOrder;
	};

	/** CCWavesTiles3D action. */
	class CCX_DLL CCWavesTiles3D : public CCTiledGrid3DAction
	{
	public:
		inline float getAmplitude(void) { return m_fAmplitude; }
		inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

		inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
		inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

		bool initWithWaves(int wav, float amp, ccGridSize gridSize, ccTime duration);

		virtual NSObject* copyWithZone(NSZone* pZone);
		virtual void update(ccTime time);

	public:
		static CCWavesTiles3D* actionWithWaves(int wav, float amp, ccGridSize gridSize, ccTime duration);

	protected:
		int m_nWaves;
		float m_fAmplitude;
		float m_fAmplitudeRate;
	};

	/** CCJumpTiles3D action.
	 A sin function is executed to move the tiles across the Z axis
	 */
	class CCX_DLL CCJumpTiles3D : public CCTiledGrid3DAction
	{
	public:
		inline float getAmplitude(void) { return m_fAmplitude; }
		inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

		inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
		inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

		bool initWithJumps(int j, float amp, ccGridSize gridSize, ccTime duration);
		virtual NSObject* copyWithZone(NSZone* pZone);
		virtual void update(ccTime time);

	public:
        static CCJumpTiles3D* actionWithJumps(int j, float amp, ccGridSize gridSize, ccTime duration);

	protected:
		int m_nJumps;
		float m_fAmplitude;
		float m_fAmplitudeRate;
	};

	/** CCSplitRows action */
	class CCX_DLL CCSplitRows : public CCTiledGrid3DAction
	{
	public :
		bool initWithRows(int nRows, ccTime duration);

		virtual NSObject* copyWithZone(NSZone* pZone);
		virtual void update(ccTime time);
		virtual void startWithTarget(CCNode *pTarget);

	public:
		static CCSplitRows* actionWithRows(int nRows, ccTime duration);

	protected:
		int m_nRows;
		CGSize m_winSize;
	};

	/** CCSplitCols action */
	class CCX_DLL CCSplitCols : public CCTiledGrid3DAction
	{
	public:
		bool initWithCols(int nCols, ccTime duration);

		virtual NSObject* copyWithZone(NSZone* pZone);
		virtual void update(ccTime time);
		virtual void startWithTarget(CCNode *pTarget);

	public:
		static CCSplitCols* actionWithCols(int nCols, ccTime duration);

	protected:
		int m_nCols;
		CGSize m_winSize;
	};
} // end of namespace cocos2d

#endif // __ACTION_CCTILEDGRID_ACTION_H__