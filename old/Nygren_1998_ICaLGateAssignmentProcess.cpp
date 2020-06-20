
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_ICaLGateAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_ICaLGateAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998_ICaLGateAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

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
    d_L_infinity->setValue( 1.00000/(1.00000+exp((v+9.00000)/-5.80000)) );
    tau_d_L->setValue( 0.00270000*exp(-(pow((v+35.0000)/30.0000, 2.00000)))+0.00200000 );
    f_L_infinity->setValue( 1.00000/(1.00000+exp((v+27.4000)/7.10000)) );
    tau_f_L1->setValue( 0.161000*exp(-(pow((v+40.0000)/14.4000, 2.00000)))+0.0100000 );
    tau_f_L2->setValue( 1.33230*exp(-(pow((v+40.0000)/14.2000, 2.00000)))+0.0626000 );

  }

 protected:

  Variable* d_L_infinity;
  Variable* tau_d_L;
  Variable* f_L_infinity;
  Variable* tau_f_L1;
  Variable* tau_f_L2;
  Variable* V;

  Real v;
};

LIBECS_DM_INIT( Nygren_1998_ICaLGateAssignmentProcess, Process );
