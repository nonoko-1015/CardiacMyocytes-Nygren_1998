
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_O_TMgCFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_O_TMgCFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_O_TMgCFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    O_TMgC  = getVariableReference( "O_TMgC" ).getVariable();
    dOTMgCdt  = getVariableReference( "dOTMgCdt" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( dOTMgCdt->getValue() );
  }

 protected:

  Variable* O_TMgC;
  Variable* dOTMgCdt;


};

LIBECS_DM_INIT( Nygren_1998v_O_TMgCFluxProcess, Process );
