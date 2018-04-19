

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <tmwtypes.h>
#include "ctrl_docurrentctrl.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void CTRL_doCurrentCtrl_Outputs_wrapper(const real32_T *ts,
			const real32_T *ia,
			const real32_T *ib,
			const real32_T *ic,
			const real32_T *rs,
			const real32_T *pole,
			const real32_T *deltatheta,
			const real32_T *fyr,
			const real32_T *udc,
			const real32_T *ttop,
			const real32_T *va,
			const real32_T *vb,
			const real32_T *vc,
			real32_T *ta,
			real32_T *tb,
			real32_T *tc,
			real32_T *te,
			real_T *valfa,
			real_T *vbeta)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
	CurrentCtrl_din_type in;
    CurrentCtrl_dout_type t;
    in.ia = *ia;
    in.ib = *ib;
    in.ic = *ic;
    in.rs = *rs;
    in.pole = *pole;
    in.deltatheta = *deltatheta;
    in.fyr = *fyr;
    in.udc = *udc;
    in.ttop = *ttop;
    in.va = *va;
    in.vb = *vb;
    in.vc = *vc;
    

    CTRL_doCurrentCtrl(in,&t);
    
    

    *ta = t.ta;
    *tb = t.tb;
    *tc = t.tc;
    *te = t.te;
    *valfa = t.valfa;
    *vbeta = t.vbeta;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
