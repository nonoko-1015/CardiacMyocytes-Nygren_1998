
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_ICaLAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_ICaLAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, E_Ca_app );
    PROPERTYSLOT_SET_GET( Real, g_Ca_L );
    PROPERTYSLOT_SET_GET( Real, k_Ca );

  }

  Nygren_1998_ICaLAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, E_Ca_app );
  SIMPLE_SET_GET_METHOD( Real, g_Ca_L );
  SIMPLE_SET_GET_METHOD( Real, k_Ca );


  virtual void initialize()
  {
    Process::initialize();

    i_Ca_L  = getVariableReference( "i_Ca_L" ).getVariable();
    d_L  = getVariableReference( "d_L" ).getVariable();
    f_Ca  = getVariableReference( "f_Ca" ).getVariable();
    f_L_1  = getVariableReference( "f_L_1" ).getVariable();
    f_L_2  = getVariableReference( "f_L_2" ).getVariable();
    Ca_d  = getVariableReference( "Ca_d" ).getVariable();
    d_L_infinity  = getVariableReference( "d_L_infinity" ).getVariable();
    tau_d_L  = getVariableReference( "tau_d_L" ).getVariable();
    f_L_infinity  = getVariableReference( "f_L_infinity" ).getVariable();
    tau_f_L1  = getVariableReference( "tau_f_L1" ).getVariable();
    tau_f_L2  = getVariableReference( "tau_f_L2" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    v = V->getValue();
    i_Ca_L->setValue( 1 * (g_Ca_L*d_L->getValue()*(f_Ca->getValue()*f_L_1->getValue()+(1.00000-f_Ca->getValue())*f_L_2->getValue())*(v-E_Ca_app)) );
    f_Ca->setValue( 1 * ((Ca_d->getMolarConc()*1000)/((Ca_d->getMolarConc()*1000)+k_Ca)) );
    d_L_infinity->setValue( 1.00000/(1.00000+exp((v+9.00000)/-5.80000)) );
    tau_d_L->setValue( 0.00270000*exp(-(pow((v+35.0000)/30.0000, 2.00000)))+0.00200000 );
    f_L_infinity->setValue( 1.00000/(1.00000+exp((v+27.4000)/7.10000)) );
    tau_f_L1->setValue( 0.161000*exp(-(pow((v+40.0000)/14.4000, 2.00000)))+0.0100000 );
    tau_f_L2->setValue( 1.33230*exp(-(pow((v+40.0000)/14.2000, 2.00000)))+0.0626000 );
  }

 protected:

  Variable* i_Ca_L;
  Variable* d_L;
  Variable* f_Ca;
  Variable* f_L_1;
  Variable* f_L_2;
  Variable* Ca_d;
  Variable* d_L_infinity;
  Variable* tau_d_L;
  Variable* f_L_infinity;
  Variable* tau_f_L1;
  Variable* tau_f_L2;
  Variable* V;

  Real E_Ca_app;
  Real g_Ca_L;
  Real k_Ca;
  Real v;
};

LIBECS_DM_INIT( Nygren_1998_ICaLAssignmentProcess, Process );
