#ifndef freecloth_sim_simStepStrategyAdaptive_h
#define freecloth_sim_simStepStrategyAdaptive_h

#ifndef freecloth_simulator_package_h
#include <freecloth/simulator/package.h>
#endif

#ifndef freecloth_simulator_simStepStrategy_h
#include <freecloth/simulator/simStepStrategy.h>
#endif

#ifndef freecloth_base_baTime_h
#include <freecloth/base/baTime.h>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS

////////////////////////////////////////////////////////////////////////////////
/*!
 * \class SimStepStrategyAdaptive freecloth/simulator/simStepStrategyAdaptive.h
 * \brief Adaptive stepping strategy.
 * \pattern Strategy
 *
 * The adaptive stepping strategy defines a step as a single frame of
 * animation. The user specifies a fixed frame rate, and an adaptive stepping
 * strategy is used to make each call to step() equivalent to advancing the
 * animation by one frame.
 *
 * To achieve this, each call to the strategy step() method will likely
 * cause the simulator to be stepped several times, using a step smaller than
 * the frame period. We differentiate between calls to step(), "frames",
 * and the calls to the simulator's step function, "internal steps". An
 * adaptive stepsize is used, as per [BarWit98].
 */
class SimStepStrategyAdaptive : public SimStepStrategy
{
public:

    // ----- types and enumerations -----
    typedef SimStepStrategy BaseClass;

    // ----- member functions -----

    //! Frame rate is number of frames per second
    SimStepStrategyAdaptive(
        const RCShdPtr<Simulator>& simulator,
        UInt32 frameRate
    );

    virtual void rewind();
    virtual bool subStepsDone() const;
    virtual void preSubSteps();
    virtual void subStep();
    virtual void postSubSteps();
    virtual void cancelStep();
    virtual bool inStep() const;
    virtual bool stepSucceeded() const;

    void setFrameRate( UInt32 );
    UInt32 getFrameRate() const;

private:
    // ----- member functions -----

    //! Grow or shrink the timestep. Adds inc to _size, and updates _h to match.
    void changeStep( Int32 inc );

    // ----- data members -----
    UInt32 _frameRate;
    bool _inStep;
    BaTime::Duration _h;
    //! Number of internal steps to wait before trying to increase step size
    UInt32 _nbInternalStepsInc;
    //! Number of internal steps taken towards wait count.
    UInt32 _nbInternalSteps;
    //! Current frame number.
    UInt32 _frame;
    //! Time at end of internal step.
    BaTime::Instant _stepEnd;

    //! Substeps executed within this internal step. Internal step is
    //! cancelled if these exceed maxSubSteps.
    UInt32 _nbSubSteps;
    const UInt32 _maxSubSteps;

    //! This indirectly determines _h. See changeStep() for details.
    Int32 _size;

    //! True if this step is a full step by _h; false if it's a partial step
    //! less than _h to reach the end of frame.
    bool _fullStep;
    bool _doneSubSteps;
    bool _stepFailed;
};

////////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTIONS
//

FREECLOTH_NAMESPACE_END

#endif
