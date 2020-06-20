
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998voiFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998voiFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998voiFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    voi  = getVariableReference( "voi" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( 1.0 );
  }

 protected:

  Variable* voi;


};

LIBECS_DM_INIT( Nygren_1998voiFluxProcess, Process );
