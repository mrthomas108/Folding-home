/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Mon Jan 16 09:08:39 EST 2017 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 32 -name n1fv_32 -include n1f.h */

/*
 * This function contains 186 FP additions, 98 FP multiplications,
 * (or, 88 additions, 0 multiplications, 98 fused multiply/add),
 * 104 stack variables, 7 constants, and 64 memory accesses
 */
#include "n1f.h"

static void n1fv_32(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP980785280, +0.980785280403230449126182236134239036973933731);
     DVK(KP831469612, +0.831469612302545237078788377617905756738560812);
     DVK(KP198912367, +0.198912367379658006911597622644676228597850501);
     DVK(KP668178637, +0.668178637919298919997757686523080761552472251);
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP414213562, +0.414213562373095048801688724209698078569671875);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(64, is), MAKE_VOLATILE_STRIDE(64, os)) {
	       V T1h, Tr, T1a, T1k, TI, T1b, T1L, T1P, T1I, T1G, T1O, T1Q, T1H, T1z, T1c;
	       V TZ;
	       {
		    V T2x, T1T, T2K, T1W, T1p, Tb, T1A, T16, Tu, TF, T2N, T2H, T2b, T2t, TY;
		    V T1w, TT, T1v, T20, T2C, Tj, Te, T2h, To, T2f, T23, T2D, TB, TG, Th;
		    V T2i, Tk;
		    {
			 V TL, TW, TP, TQ, T2F, T27, T28, TO;
			 {
			      V T1, T2, T12, T13, T4, T5, T7, T8;
			      T1 = LD(&(xi[0]), ivs, &(xi[0]));
			      T2 = LD(&(xi[WS(is, 16)]), ivs, &(xi[0]));
			      T12 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			      T13 = LD(&(xi[WS(is, 24)]), ivs, &(xi[0]));
			      T4 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			      T5 = LD(&(xi[WS(is, 20)]), ivs, &(xi[0]));
			      T7 = LD(&(xi[WS(is, 28)]), ivs, &(xi[0]));
			      T8 = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			      {
				   V TM, T25, T26, TN;
				   {
					V TJ, T3, T14, T1U, T6, T1V, T9, TK, TU, TV, T1R, T1S, Ta, T15;
					TJ = LD(&(xi[WS(is, 31)]), ivs, &(xi[WS(is, 1)]));
					T1R = VADD(T1, T2);
					T3 = VSUB(T1, T2);
					T1S = VADD(T12, T13);
					T14 = VSUB(T12, T13);
					T1U = VADD(T4, T5);
					T6 = VSUB(T4, T5);
					T1V = VADD(T7, T8);
					T9 = VSUB(T7, T8);
					TK = LD(&(xi[WS(is, 15)]), ivs, &(xi[WS(is, 1)]));
					TU = LD(&(xi[WS(is, 23)]), ivs, &(xi[WS(is, 1)]));
					T2x = VSUB(T1R, T1S);
					T1T = VADD(T1R, T1S);
					TV = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
					TM = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
					T2K = VSUB(T1V, T1U);
					T1W = VADD(T1U, T1V);
					Ta = VADD(T6, T9);
					T15 = VSUB(T9, T6);
					T25 = VADD(TJ, TK);
					TL = VSUB(TJ, TK);
					T26 = VADD(TV, TU);
					TW = VSUB(TU, TV);
					TN = LD(&(xi[WS(is, 19)]), ivs, &(xi[WS(is, 1)]));
					TP = LD(&(xi[WS(is, 27)]), ivs, &(xi[WS(is, 1)]));
					T1p = VFNMS(LDK(KP707106781), Ta, T3);
					Tb = VFMA(LDK(KP707106781), Ta, T3);
					T1A = VFMA(LDK(KP707106781), T15, T14);
					T16 = VFNMS(LDK(KP707106781), T15, T14);
					TQ = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
				   }
				   T2F = VSUB(T25, T26);
				   T27 = VADD(T25, T26);
				   T28 = VADD(TM, TN);
				   TO = VSUB(TM, TN);
			      }
			 }
			 {
			      V Ty, T21, Tx, Tz, T1Y, T1Z;
			      {
				   V Ts, Tt, TD, T29, TR, TE, Tv, Tw;
				   Ts = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
				   Tt = LD(&(xi[WS(is, 17)]), ivs, &(xi[WS(is, 1)]));
				   TD = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
				   T29 = VADD(TP, TQ);
				   TR = VSUB(TP, TQ);
				   TE = LD(&(xi[WS(is, 25)]), ivs, &(xi[WS(is, 1)]));
				   Tv = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
				   Tw = LD(&(xi[WS(is, 21)]), ivs, &(xi[WS(is, 1)]));
				   Ty = LD(&(xi[WS(is, 29)]), ivs, &(xi[WS(is, 1)]));
				   T1Y = VADD(Ts, Tt);
				   Tu = VSUB(Ts, Tt);
				   {
					V T2G, T2a, TX, TS;
					T2G = VSUB(T29, T28);
					T2a = VADD(T28, T29);
					TX = VSUB(TR, TO);
					TS = VADD(TO, TR);
					T1Z = VADD(TD, TE);
					TF = VSUB(TD, TE);
					T21 = VADD(Tv, Tw);
					Tx = VSUB(Tv, Tw);
					T2N = VFMA(LDK(KP414213562), T2F, T2G);
					T2H = VFNMS(LDK(KP414213562), T2G, T2F);
					T2b = VSUB(T27, T2a);
					T2t = VADD(T27, T2a);
					TY = VFMA(LDK(KP707106781), TX, TW);
					T1w = VFNMS(LDK(KP707106781), TX, TW);
					TT = VFMA(LDK(KP707106781), TS, TL);
					T1v = VFNMS(LDK(KP707106781), TS, TL);
					Tz = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
				   }
			      }
			      T20 = VADD(T1Y, T1Z);
			      T2C = VSUB(T1Y, T1Z);
			      {
				   V Tc, Td, Tm, Tn;
				   Tc = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
				   Td = LD(&(xi[WS(is, 18)]), ivs, &(xi[0]));
				   Tm = LD(&(xi[WS(is, 22)]), ivs, &(xi[0]));
				   Tn = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
				   {
					V Tf, TA, T22, Tg;
					Tf = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
					TA = VSUB(Ty, Tz);
					T22 = VADD(Ty, Tz);
					Tg = LD(&(xi[WS(is, 26)]), ivs, &(xi[0]));
					Tj = LD(&(xi[WS(is, 30)]), ivs, &(xi[0]));
					Te = VSUB(Tc, Td);
					T2h = VADD(Tc, Td);
					To = VSUB(Tm, Tn);
					T2f = VADD(Tn, Tm);
					T23 = VADD(T21, T22);
					T2D = VSUB(T21, T22);
					TB = VADD(Tx, TA);
					TG = VSUB(Tx, TA);
					Th = VSUB(Tf, Tg);
					T2i = VADD(Tf, Tg);
					Tk = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
				   }
			      }
			 }
		    }
		    {
			 V T1t, TH, T1s, TC, T2P, T2U, T2n, T2d, T2w, T2u, T1q, T19, T1B, Tq, T2W;
			 V T2M, T2B, T2T, T2v, T2r, T2o, T2m, T2X, T2I;
			 {
			      V T1X, T2p, T2E, T2O, T2s, T2y, T2j, T17, Ti, T2e, Tl, T2c, T2l, T24;
			      T1X = VSUB(T1T, T1W);
			      T2p = VADD(T1T, T1W);
			      T2E = VFNMS(LDK(KP414213562), T2D, T2C);
			      T2O = VFMA(LDK(KP414213562), T2C, T2D);
			      T2s = VADD(T20, T23);
			      T24 = VSUB(T20, T23);
			      T1t = VFNMS(LDK(KP707106781), TG, TF);
			      TH = VFMA(LDK(KP707106781), TG, TF);
			      T1s = VFNMS(LDK(KP707106781), TB, Tu);
			      TC = VFMA(LDK(KP707106781), TB, Tu);
			      T2y = VSUB(T2h, T2i);
			      T2j = VADD(T2h, T2i);
			      T17 = VFMA(LDK(KP414213562), Te, Th);
			      Ti = VFNMS(LDK(KP414213562), Th, Te);
			      T2e = VADD(Tj, Tk);
			      Tl = VSUB(Tj, Tk);
			      T2c = VADD(T24, T2b);
			      T2l = VSUB(T2b, T24);
			      {
				   V T2L, T2A, T2q, T2k;
				   T2P = VSUB(T2N, T2O);
				   T2U = VADD(T2O, T2N);
				   {
					V T2z, T2g, T18, Tp;
					T2z = VSUB(T2e, T2f);
					T2g = VADD(T2e, T2f);
					T18 = VFMA(LDK(KP414213562), Tl, To);
					Tp = VFNMS(LDK(KP414213562), To, Tl);
					T2n = VFMA(LDK(KP707106781), T2c, T1X);
					T2d = VFNMS(LDK(KP707106781), T2c, T1X);
					T2w = VSUB(T2t, T2s);
					T2u = VADD(T2s, T2t);
					T2L = VSUB(T2z, T2y);
					T2A = VADD(T2y, T2z);
					T2q = VADD(T2j, T2g);
					T2k = VSUB(T2g, T2j);
					T1q = VADD(T17, T18);
					T19 = VSUB(T17, T18);
					T1B = VSUB(Tp, Ti);
					Tq = VADD(Ti, Tp);
				   }
				   T2W = VFNMS(LDK(KP707106781), T2L, T2K);
				   T2M = VFMA(LDK(KP707106781), T2L, T2K);
				   T2B = VFMA(LDK(KP707106781), T2A, T2x);
				   T2T = VFNMS(LDK(KP707106781), T2A, T2x);
				   T2v = VSUB(T2p, T2q);
				   T2r = VADD(T2p, T2q);
				   T2o = VFMA(LDK(KP707106781), T2l, T2k);
				   T2m = VFNMS(LDK(KP707106781), T2l, T2k);
				   T2X = VSUB(T2H, T2E);
				   T2I = VADD(T2E, T2H);
			      }
			 }
			 {
			      V T2V, T2Z, T2Y, T30, T2R, T2J;
			      T2V = VFNMS(LDK(KP923879532), T2U, T2T);
			      T2Z = VFMA(LDK(KP923879532), T2U, T2T);
			      ST(&(xo[WS(os, 24)]), VFNMSI(T2w, T2v), ovs, &(xo[0]));
			      ST(&(xo[WS(os, 8)]), VFMAI(T2w, T2v), ovs, &(xo[0]));
			      ST(&(xo[0]), VADD(T2r, T2u), ovs, &(xo[0]));
			      ST(&(xo[WS(os, 16)]), VSUB(T2r, T2u), ovs, &(xo[0]));
			      ST(&(xo[WS(os, 28)]), VFNMSI(T2o, T2n), ovs, &(xo[0]));
			      ST(&(xo[WS(os, 4)]), VFMAI(T2o, T2n), ovs, &(xo[0]));
			      ST(&(xo[WS(os, 20)]), VFMAI(T2m, T2d), ovs, &(xo[0]));
			      ST(&(xo[WS(os, 12)]), VFNMSI(T2m, T2d), ovs, &(xo[0]));
			      T2Y = VFMA(LDK(KP923879532), T2X, T2W);
			      T30 = VFNMS(LDK(KP923879532), T2X, T2W);
			      T2R = VFMA(LDK(KP923879532), T2I, T2B);
			      T2J = VFNMS(LDK(KP923879532), T2I, T2B);
			      {
				   V T1J, T1r, T1C, T1M, T2S, T2Q, T1u, T1D, T1E, T1x;
				   T1J = VFNMS(LDK(KP923879532), T1q, T1p);
				   T1r = VFMA(LDK(KP923879532), T1q, T1p);
				   T1C = VFMA(LDK(KP923879532), T1B, T1A);
				   T1M = VFNMS(LDK(KP923879532), T1B, T1A);
				   ST(&(xo[WS(os, 6)]), VFNMSI(T30, T2Z), ovs, &(xo[0]));
				   ST(&(xo[WS(os, 26)]), VFMAI(T30, T2Z), ovs, &(xo[0]));
				   ST(&(xo[WS(os, 22)]), VFNMSI(T2Y, T2V), ovs, &(xo[0]));
				   ST(&(xo[WS(os, 10)]), VFMAI(T2Y, T2V), ovs, &(xo[0]));
				   T2S = VFMA(LDK(KP923879532), T2P, T2M);
				   T2Q = VFNMS(LDK(KP923879532), T2P, T2M);
				   T1u = VFMA(LDK(KP668178637), T1t, T1s);
				   T1D = VFNMS(LDK(KP668178637), T1s, T1t);
				   T1E = VFNMS(LDK(KP668178637), T1v, T1w);
				   T1x = VFMA(LDK(KP668178637), T1w, T1v);
				   {
					V T1K, T1F, T1N, T1y;
					T1h = VFNMS(LDK(KP923879532), Tq, Tb);
					Tr = VFMA(LDK(KP923879532), Tq, Tb);
					ST(&(xo[WS(os, 30)]), VFNMSI(T2S, T2R), ovs, &(xo[0]));
					ST(&(xo[WS(os, 2)]), VFMAI(T2S, T2R), ovs, &(xo[0]));
					ST(&(xo[WS(os, 18)]), VFMAI(T2Q, T2J), ovs, &(xo[0]));
					ST(&(xo[WS(os, 14)]), VFNMSI(T2Q, T2J), ovs, &(xo[0]));
					T1K = VADD(T1D, T1E);
					T1F = VSUB(T1D, T1E);
					T1N = VSUB(T1x, T1u);
					T1y = VADD(T1u, T1x);
					T1a = VFMA(LDK(KP923879532), T19, T16);
					T1k = VFNMS(LDK(KP923879532), T19, T16);
					TI = VFNMS(LDK(KP198912367), TH, TC);
					T1b = VFMA(LDK(KP198912367), TC, TH);
					T1L = VFMA(LDK(KP831469612), T1K, T1J);
					T1P = VFNMS(LDK(KP831469612), T1K, T1J);
					T1I = VFMA(LDK(KP831469612), T1F, T1C);
					T1G = VFNMS(LDK(KP831469612), T1F, T1C);
					T1O = VFMA(LDK(KP831469612), T1N, T1M);
					T1Q = VFNMS(LDK(KP831469612), T1N, T1M);
					T1H = VFMA(LDK(KP831469612), T1y, T1r);
					T1z = VFNMS(LDK(KP831469612), T1y, T1r);
					T1c = VFMA(LDK(KP198912367), TT, TY);
					TZ = VFNMS(LDK(KP198912367), TY, TT);
				   }
			      }
			 }
		    }
	       }
	       {
		    V T1d, T1i, T10, T1l;
		    ST(&(xo[WS(os, 21)]), VFNMSI(T1O, T1L), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 11)]), VFMAI(T1O, T1L), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 27)]), VFMAI(T1Q, T1P), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 5)]), VFNMSI(T1Q, T1P), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 3)]), VFMAI(T1I, T1H), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 29)]), VFNMSI(T1I, T1H), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 19)]), VFMAI(T1G, T1z), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 13)]), VFNMSI(T1G, T1z), ovs, &(xo[WS(os, 1)]));
		    T1d = VSUB(T1b, T1c);
		    T1i = VADD(T1b, T1c);
		    T10 = VADD(TI, TZ);
		    T1l = VSUB(TZ, TI);
		    {
			 V T1n, T1j, T1e, T1g, T1o, T1m, T11, T1f;
			 T1n = VFMA(LDK(KP980785280), T1i, T1h);
			 T1j = VFNMS(LDK(KP980785280), T1i, T1h);
			 T1e = VFNMS(LDK(KP980785280), T1d, T1a);
			 T1g = VFMA(LDK(KP980785280), T1d, T1a);
			 T1o = VFMA(LDK(KP980785280), T1l, T1k);
			 T1m = VFNMS(LDK(KP980785280), T1l, T1k);
			 T11 = VFNMS(LDK(KP980785280), T10, Tr);
			 T1f = VFMA(LDK(KP980785280), T10, Tr);
			 ST(&(xo[WS(os, 23)]), VFMAI(T1m, T1j), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 9)]), VFNMSI(T1m, T1j), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 25)]), VFNMSI(T1o, T1n), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 7)]), VFMAI(T1o, T1n), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 31)]), VFMAI(T1g, T1f), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 1)]), VFNMSI(T1g, T1f), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 15)]), VFMAI(T1e, T11), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 17)]), VFNMSI(T1e, T11), ovs, &(xo[WS(os, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 32, XSIMD_STRING("n1fv_32"), {88, 0, 98, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_32) (planner *p) {
     X(kdft_register) (p, n1fv_32, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 32 -name n1fv_32 -include n1f.h */

/*
 * This function contains 186 FP additions, 42 FP multiplications,
 * (or, 170 additions, 26 multiplications, 16 fused multiply/add),
 * 58 stack variables, 7 constants, and 64 memory accesses
 */
#include "n1f.h"

static void n1fv_32(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP195090322, +0.195090322016128267848284868477022240927691618);
     DVK(KP980785280, +0.980785280403230449126182236134239036973933731);
     DVK(KP555570233, +0.555570233019602224742830813948532874374937191);
     DVK(KP831469612, +0.831469612302545237078788377617905756738560812);
     DVK(KP382683432, +0.382683432365089771728459984030398866761344562);
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(64, is), MAKE_VOLATILE_STRIDE(64, os)) {
	       V T1T, T1W, T2K, T2x, T16, T1A, Tb, T1p, TT, T1v, TY, T1w, T27, T2a, T2b;
	       V T2H, T2O, TC, T1s, TH, T1t, T20, T23, T24, T2E, T2N, T2g, T2j, Tq, T1B;
	       V T19, T1q, T2A, T2L;
	       {
		    V T3, T1R, T15, T1S, T6, T1U, T9, T1V, T12, Ta;
		    {
			 V T1, T2, T13, T14;
			 T1 = LD(&(xi[0]), ivs, &(xi[0]));
			 T2 = LD(&(xi[WS(is, 16)]), ivs, &(xi[0]));
			 T3 = VSUB(T1, T2);
			 T1R = VADD(T1, T2);
			 T13 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 T14 = LD(&(xi[WS(is, 24)]), ivs, &(xi[0]));
			 T15 = VSUB(T13, T14);
			 T1S = VADD(T13, T14);
		    }
		    {
			 V T4, T5, T7, T8;
			 T4 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 20)]), ivs, &(xi[0]));
			 T6 = VSUB(T4, T5);
			 T1U = VADD(T4, T5);
			 T7 = LD(&(xi[WS(is, 28)]), ivs, &(xi[0]));
			 T8 = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			 T9 = VSUB(T7, T8);
			 T1V = VADD(T7, T8);
		    }
		    T1T = VADD(T1R, T1S);
		    T1W = VADD(T1U, T1V);
		    T2K = VSUB(T1V, T1U);
		    T2x = VSUB(T1R, T1S);
		    T12 = VMUL(LDK(KP707106781), VSUB(T9, T6));
		    T16 = VSUB(T12, T15);
		    T1A = VADD(T15, T12);
		    Ta = VMUL(LDK(KP707106781), VADD(T6, T9));
		    Tb = VADD(T3, Ta);
		    T1p = VSUB(T3, Ta);
	       }
	       {
		    V TL, T25, TX, T26, TO, T28, TR, T29;
		    {
			 V TJ, TK, TV, TW;
			 TJ = LD(&(xi[WS(is, 31)]), ivs, &(xi[WS(is, 1)]));
			 TK = LD(&(xi[WS(is, 15)]), ivs, &(xi[WS(is, 1)]));
			 TL = VSUB(TJ, TK);
			 T25 = VADD(TJ, TK);
			 TV = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 TW = LD(&(xi[WS(is, 23)]), ivs, &(xi[WS(is, 1)]));
			 TX = VSUB(TV, TW);
			 T26 = VADD(TV, TW);
		    }
		    {
			 V TM, TN, TP, TQ;
			 TM = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 TN = LD(&(xi[WS(is, 19)]), ivs, &(xi[WS(is, 1)]));
			 TO = VSUB(TM, TN);
			 T28 = VADD(TM, TN);
			 TP = LD(&(xi[WS(is, 27)]), ivs, &(xi[WS(is, 1)]));
			 TQ = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			 TR = VSUB(TP, TQ);
			 T29 = VADD(TP, TQ);
		    }
		    {
			 V TS, TU, T2F, T2G;
			 TS = VMUL(LDK(KP707106781), VADD(TO, TR));
			 TT = VADD(TL, TS);
			 T1v = VSUB(TL, TS);
			 TU = VMUL(LDK(KP707106781), VSUB(TR, TO));
			 TY = VSUB(TU, TX);
			 T1w = VADD(TX, TU);
			 T27 = VADD(T25, T26);
			 T2a = VADD(T28, T29);
			 T2b = VSUB(T27, T2a);
			 T2F = VSUB(T25, T26);
			 T2G = VSUB(T29, T28);
			 T2H = VFNMS(LDK(KP382683432), T2G, VMUL(LDK(KP923879532), T2F));
			 T2O = VFMA(LDK(KP382683432), T2F, VMUL(LDK(KP923879532), T2G));
		    }
	       }
	       {
		    V Tu, T1Y, TG, T1Z, Tx, T21, TA, T22;
		    {
			 V Ts, Tt, TE, TF;
			 Ts = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Tt = LD(&(xi[WS(is, 17)]), ivs, &(xi[WS(is, 1)]));
			 Tu = VSUB(Ts, Tt);
			 T1Y = VADD(Ts, Tt);
			 TE = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 TF = LD(&(xi[WS(is, 25)]), ivs, &(xi[WS(is, 1)]));
			 TG = VSUB(TE, TF);
			 T1Z = VADD(TE, TF);
		    }
		    {
			 V Tv, Tw, Ty, Tz;
			 Tv = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
			 Tw = LD(&(xi[WS(is, 21)]), ivs, &(xi[WS(is, 1)]));
			 Tx = VSUB(Tv, Tw);
			 T21 = VADD(Tv, Tw);
			 Ty = LD(&(xi[WS(is, 29)]), ivs, &(xi[WS(is, 1)]));
			 Tz = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
			 TA = VSUB(Ty, Tz);
			 T22 = VADD(Ty, Tz);
		    }
		    {
			 V TB, TD, T2C, T2D;
			 TB = VMUL(LDK(KP707106781), VADD(Tx, TA));
			 TC = VADD(Tu, TB);
			 T1s = VSUB(Tu, TB);
			 TD = VMUL(LDK(KP707106781), VSUB(TA, Tx));
			 TH = VSUB(TD, TG);
			 T1t = VADD(TG, TD);
			 T20 = VADD(T1Y, T1Z);
			 T23 = VADD(T21, T22);
			 T24 = VSUB(T20, T23);
			 T2C = VSUB(T1Y, T1Z);
			 T2D = VSUB(T22, T21);
			 T2E = VFMA(LDK(KP923879532), T2C, VMUL(LDK(KP382683432), T2D));
			 T2N = VFNMS(LDK(KP382683432), T2C, VMUL(LDK(KP923879532), T2D));
		    }
	       }
	       {
		    V Te, T2h, To, T2f, Th, T2i, Tl, T2e, Ti, Tp;
		    {
			 V Tc, Td, Tm, Tn;
			 Tc = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 Td = LD(&(xi[WS(is, 18)]), ivs, &(xi[0]));
			 Te = VSUB(Tc, Td);
			 T2h = VADD(Tc, Td);
			 Tm = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 Tn = LD(&(xi[WS(is, 22)]), ivs, &(xi[0]));
			 To = VSUB(Tm, Tn);
			 T2f = VADD(Tm, Tn);
		    }
		    {
			 V Tf, Tg, Tj, Tk;
			 Tf = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
			 Tg = LD(&(xi[WS(is, 26)]), ivs, &(xi[0]));
			 Th = VSUB(Tf, Tg);
			 T2i = VADD(Tf, Tg);
			 Tj = LD(&(xi[WS(is, 30)]), ivs, &(xi[0]));
			 Tk = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
			 Tl = VSUB(Tj, Tk);
			 T2e = VADD(Tj, Tk);
		    }
		    T2g = VADD(T2e, T2f);
		    T2j = VADD(T2h, T2i);
		    Ti = VFNMS(LDK(KP382683432), Th, VMUL(LDK(KP923879532), Te));
		    Tp = VFMA(LDK(KP923879532), Tl, VMUL(LDK(KP382683432), To));
		    Tq = VADD(Ti, Tp);
		    T1B = VSUB(Tp, Ti);
		    {
			 V T17, T18, T2y, T2z;
			 T17 = VFNMS(LDK(KP923879532), To, VMUL(LDK(KP382683432), Tl));
			 T18 = VFMA(LDK(KP382683432), Te, VMUL(LDK(KP923879532), Th));
			 T19 = VSUB(T17, T18);
			 T1q = VADD(T18, T17);
			 T2y = VSUB(T2h, T2i);
			 T2z = VSUB(T2e, T2f);
			 T2A = VMUL(LDK(KP707106781), VADD(T2y, T2z));
			 T2L = VMUL(LDK(KP707106781), VSUB(T2z, T2y));
		    }
	       }
	       {
		    V T2d, T2n, T2m, T2o;
		    {
			 V T1X, T2c, T2k, T2l;
			 T1X = VSUB(T1T, T1W);
			 T2c = VMUL(LDK(KP707106781), VADD(T24, T2b));
			 T2d = VADD(T1X, T2c);
			 T2n = VSUB(T1X, T2c);
			 T2k = VSUB(T2g, T2j);
			 T2l = VMUL(LDK(KP707106781), VSUB(T2b, T24));
			 T2m = VBYI(VADD(T2k, T2l));
			 T2o = VBYI(VSUB(T2l, T2k));
		    }
		    ST(&(xo[WS(os, 28)]), VSUB(T2d, T2m), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 12)]), VADD(T2n, T2o), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 4)]), VADD(T2d, T2m), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 20)]), VSUB(T2n, T2o), ovs, &(xo[0]));
	       }
	       {
		    V T2r, T2v, T2u, T2w;
		    {
			 V T2p, T2q, T2s, T2t;
			 T2p = VADD(T1T, T1W);
			 T2q = VADD(T2j, T2g);
			 T2r = VADD(T2p, T2q);
			 T2v = VSUB(T2p, T2q);
			 T2s = VADD(T20, T23);
			 T2t = VADD(T27, T2a);
			 T2u = VADD(T2s, T2t);
			 T2w = VBYI(VSUB(T2t, T2s));
		    }
		    ST(&(xo[WS(os, 16)]), VSUB(T2r, T2u), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 8)]), VADD(T2v, T2w), ovs, &(xo[0]));
		    ST(&(xo[0]), VADD(T2r, T2u), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 24)]), VSUB(T2v, T2w), ovs, &(xo[0]));
	       }
	       {
		    V T2V, T2Z, T2Y, T30;
		    {
			 V T2T, T2U, T2W, T2X;
			 T2T = VSUB(T2H, T2E);
			 T2U = VSUB(T2L, T2K);
			 T2V = VBYI(VSUB(T2T, T2U));
			 T2Z = VBYI(VADD(T2U, T2T));
			 T2W = VSUB(T2x, T2A);
			 T2X = VSUB(T2O, T2N);
			 T2Y = VSUB(T2W, T2X);
			 T30 = VADD(T2W, T2X);
		    }
		    ST(&(xo[WS(os, 10)]), VADD(T2V, T2Y), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 26)]), VSUB(T30, T2Z), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 22)]), VSUB(T2Y, T2V), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 6)]), VADD(T2Z, T30), ovs, &(xo[0]));
	       }
	       {
		    V T2J, T2R, T2Q, T2S;
		    {
			 V T2B, T2I, T2M, T2P;
			 T2B = VADD(T2x, T2A);
			 T2I = VADD(T2E, T2H);
			 T2J = VADD(T2B, T2I);
			 T2R = VSUB(T2B, T2I);
			 T2M = VADD(T2K, T2L);
			 T2P = VADD(T2N, T2O);
			 T2Q = VBYI(VADD(T2M, T2P));
			 T2S = VBYI(VSUB(T2P, T2M));
		    }
		    ST(&(xo[WS(os, 30)]), VSUB(T2J, T2Q), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 14)]), VADD(T2R, T2S), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 2)]), VADD(T2J, T2Q), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 18)]), VSUB(T2R, T2S), ovs, &(xo[0]));
	       }
	       {
		    V T1r, T1C, T1M, T1K, T1F, T1N, T1y, T1J;
		    T1r = VADD(T1p, T1q);
		    T1C = VADD(T1A, T1B);
		    T1M = VSUB(T1p, T1q);
		    T1K = VSUB(T1B, T1A);
		    {
			 V T1D, T1E, T1u, T1x;
			 T1D = VFNMS(LDK(KP555570233), T1s, VMUL(LDK(KP831469612), T1t));
			 T1E = VFMA(LDK(KP555570233), T1v, VMUL(LDK(KP831469612), T1w));
			 T1F = VADD(T1D, T1E);
			 T1N = VSUB(T1E, T1D);
			 T1u = VFMA(LDK(KP831469612), T1s, VMUL(LDK(KP555570233), T1t));
			 T1x = VFNMS(LDK(KP555570233), T1w, VMUL(LDK(KP831469612), T1v));
			 T1y = VADD(T1u, T1x);
			 T1J = VSUB(T1x, T1u);
		    }
		    {
			 V T1z, T1G, T1P, T1Q;
			 T1z = VADD(T1r, T1y);
			 T1G = VBYI(VADD(T1C, T1F));
			 ST(&(xo[WS(os, 29)]), VSUB(T1z, T1G), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 3)]), VADD(T1z, T1G), ovs, &(xo[WS(os, 1)]));
			 T1P = VBYI(VADD(T1K, T1J));
			 T1Q = VADD(T1M, T1N);
			 ST(&(xo[WS(os, 5)]), VADD(T1P, T1Q), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 27)]), VSUB(T1Q, T1P), ovs, &(xo[WS(os, 1)]));
		    }
		    {
			 V T1H, T1I, T1L, T1O;
			 T1H = VSUB(T1r, T1y);
			 T1I = VBYI(VSUB(T1F, T1C));
			 ST(&(xo[WS(os, 19)]), VSUB(T1H, T1I), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 13)]), VADD(T1H, T1I), ovs, &(xo[WS(os, 1)]));
			 T1L = VBYI(VSUB(T1J, T1K));
			 T1O = VSUB(T1M, T1N);
			 ST(&(xo[WS(os, 11)]), VADD(T1L, T1O), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 21)]), VSUB(T1O, T1L), ovs, &(xo[WS(os, 1)]));
		    }
	       }
	       {
		    V Tr, T1a, T1k, T1i, T1d, T1l, T10, T1h;
		    Tr = VADD(Tb, Tq);
		    T1a = VADD(T16, T19);
		    T1k = VSUB(Tb, Tq);
		    T1i = VSUB(T19, T16);
		    {
			 V T1b, T1c, TI, TZ;
			 T1b = VFNMS(LDK(KP195090322), TC, VMUL(LDK(KP980785280), TH));
			 T1c = VFMA(LDK(KP195090322), TT, VMUL(LDK(KP980785280), TY));
			 T1d = VADD(T1b, T1c);
			 T1l = VSUB(T1c, T1b);
			 TI = VFMA(LDK(KP980785280), TC, VMUL(LDK(KP195090322), TH));
			 TZ = VFNMS(LDK(KP195090322), TY, VMUL(LDK(KP980785280), TT));
			 T10 = VADD(TI, TZ);
			 T1h = VSUB(TZ, TI);
		    }
		    {
			 V T11, T1e, T1n, T1o;
			 T11 = VADD(Tr, T10);
			 T1e = VBYI(VADD(T1a, T1d));
			 ST(&(xo[WS(os, 31)]), VSUB(T11, T1e), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 1)]), VADD(T11, T1e), ovs, &(xo[WS(os, 1)]));
			 T1n = VBYI(VADD(T1i, T1h));
			 T1o = VADD(T1k, T1l);
			 ST(&(xo[WS(os, 7)]), VADD(T1n, T1o), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 25)]), VSUB(T1o, T1n), ovs, &(xo[WS(os, 1)]));
		    }
		    {
			 V T1f, T1g, T1j, T1m;
			 T1f = VSUB(Tr, T10);
			 T1g = VBYI(VSUB(T1d, T1a));
			 ST(&(xo[WS(os, 17)]), VSUB(T1f, T1g), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 15)]), VADD(T1f, T1g), ovs, &(xo[WS(os, 1)]));
			 T1j = VBYI(VSUB(T1h, T1i));
			 T1m = VSUB(T1k, T1l);
			 ST(&(xo[WS(os, 9)]), VADD(T1j, T1m), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 23)]), VSUB(T1m, T1j), ovs, &(xo[WS(os, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 32, XSIMD_STRING("n1fv_32"), {170, 26, 16, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_32) (planner *p) {
     X(kdft_register) (p, n1fv_32, &desc);
}

#endif				/* HAVE_FMA */
