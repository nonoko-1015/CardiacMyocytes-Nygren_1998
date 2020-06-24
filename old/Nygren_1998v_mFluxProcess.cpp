
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_mFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_mFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_mFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    m  = getVariableReference( "m" ).getVariable();
    m_infinity  = getVariableReference( "m_infinity" ).getVariable();
    tau_m  = getVariableReference( "tau_m" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (m_infinity->getValue()-m->getValue())/tau_m->getValue() );
  }

 protected:

  Variable* m;
  Variable* m_infinity;
  Variable* tau_m;


};

LIBECS_DM_INIT( Nygren_1998v_mFluxProcess, Process );
