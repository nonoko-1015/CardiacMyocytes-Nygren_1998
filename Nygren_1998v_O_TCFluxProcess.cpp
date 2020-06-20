
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_O_TCFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_O_TCFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_O_TCFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    O_TC  = getVariableReference( "O_TC" ).getVariable();
    dOTCdt  = getVariableReference( "dOTCdt" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( dOTCdt->getValue() );
  }

 protected:

  Variable* O_TC;
  Variable* dOTCdt;


};

LIBECS_DM_INIT( Nygren_1998v_O_TCFluxProcess, Process );
