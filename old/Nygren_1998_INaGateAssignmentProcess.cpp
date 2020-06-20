
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_INaGateAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_INaGateAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

  }

  Nygren_1998_INaGateAssignmentProcess()
  {
    // do nothing
  }

  virtual void initialize()
  {
    Process::initialize();

    V  = getVariableReference( "V" ).getVariable();
    m_infinity  = getVariableReference( "m_infinity" ).getVariable();
    tau_m  = getVariableReference( "tau_m" ).getVariable();
    h_infinity  = getVariableReference( "h_infinity" ).getVariable();
    tau_h1  = getVariableReference( "tau_h1" ).getVariable();
    tau_h2  = getVariableReference( "tau_h2" ).getVariable();

  }

  virtual void fire()
  {
    v = V->getValue();
    m_infinity->setValue( 1.00000/(1.00000+exp((v+27.1200)/-8.21000)) );
    tau_m->setValue( 4.20000e-05*exp(-(pow((v+25.5700)/28.8000, 2.00000)))+2.40000e-05 );
    h_infinity->setValue( 1.00000/(1.00000+exp((v+63.6000)/5.30000)) );
    tau_h1->setValue( 0.0300000/(1.00000+exp((v+35.1000)/3.20000))+0.000300000 );
    tau_h2->setValue( 0.120000/(1.00000+exp((v+35.1000)/3.20000))+0.00300000 );
  }

 protected:

  Variable* V;
  Variable* m_infinity;
  Variable* tau_m;
  Variable* h_infinity;
  Variable* tau_h1;
  Variable* tau_h2;

  Real v;
};

LIBECS_DM_INIT( Nygren_1998_INaGateAssignmentProcess, Process );
