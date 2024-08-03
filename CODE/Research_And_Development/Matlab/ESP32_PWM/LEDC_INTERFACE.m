classdef LEDC_INTERFACE < matlab.System ...
        & coder.ExternalDependency ...
        & matlabshared.sensors.simulink.internal.BlockSampleTime

    % LEDC PWM Control Block
    %#codegen
    %#ok<*EMCA>

    properties

    end

    properties(Access = protected)
        Logo = 'IO Device Builder';
    end

    properties (Nontunable)
        PWM_CHANNEL = int16(0);
        PWM_FREQUENCY = int16(0);
        PWM_RESOLUTION = int16(0);
        PWM_PIN = int16(0);
        PWM_Clock_Speed = int64(0);
    end

    properties (Access = private)


    end

    methods
        % Constructor
        function obj = LEDC_INTERFACE(varargin)
            setProperties(obj,nargin,varargin{:});
        end
    end

    methods (Access=protected)
        function setupImpl(obj)
            if ~coder.target('MATLAB')
                coder.cinclude('LEDC_INTERFACE.h');
                coder.ceval('setupFunctionLEDC_INTERFACE', (obj.PWM_CHANNEL),1, (obj.PWM_FREQUENCY),1, (obj.PWM_RESOLUTION),1, (obj.PWM_PIN),1, (obj.PWM_Clock_Speed),1);
            end
        end

        function validateInputsImpl(obj,varargin)
            %  Check the input size
            if nargin ~=0

            %    validateattributes(varargin{1},{'int16'},{'2d','size',[1,1]},'','Duty_Cycle_Percent');

            end
        end

        function stepImpl(obj ,Duty_Cycle_Percent)

            if isempty(coder.target)
            else
                coder.ceval('stepFunctionLEDC_INTERFACE', Duty_Cycle_Percent,1);
            end
        end

        function releaseImpl(obj)
            if isempty(coder.target)
            else

            end
        end
    end

    methods (Access=protected)
        %% Define output properties
        function num = getNumInputsImpl(~)
            num = 1;
        end

        function num = getNumOutputsImpl(~)
            num = 0;
        end

        function varargout = getInputNamesImpl(obj)
            varargout{1} = 'Duty_Cycle_Percent';

        end

        function varargout = getOutputNamesImpl(obj)

        end

        function flag = isOutputSizeLockedImpl(~,~)
            flag = true;
        end

        function varargout = isOutputFixedSizeImpl(~,~)

        end

        function varargout = isOutputComplexImpl(~)

        end

        function varargout = getOutputSizeImpl(~)

        end

        function varargout = getOutputDataTypeImpl(~)

        end

        function maskDisplayCmds = getMaskDisplayImpl(obj)
            outport_label = [];
            num = getNumOutputsImpl(obj);
            if num > 0
                outputs = cell(1,num);
                [outputs{1:num}] = getOutputNamesImpl(obj);
                for i = 1:num
                    outport_label = [outport_label 'port_label(''output'',' num2str(i) ',''' outputs{i} ''');' ]; %#ok<AGROW>
                end
            end
            inport_label = [];
            num = getNumInputsImpl(obj);
            if num > 0
                inputs = cell(1,num);
                [inputs{1:num}] = getInputNamesImpl(obj);
                for i = 1:num
                    inport_label = [inport_label 'port_label(''input'',' num2str(i) ',''' inputs{i} ''');' ]; %#ok<AGROW>
                end
            end
            icon = 'LEDC_INTERFACE';
            maskDisplayCmds = [ ...
                ['color(''white'');',...
                'plot([100,100,100,100]*1,[100,100,100,100]*1);',...
                'plot([100,100,100,100]*0,[100,100,100,100]*0);',...
                'color(''blue'');', ...
                ['text(38, 92, ','''',obj.Logo,'''',',''horizontalAlignment'', ''right'');',newline],...
                'color(''black'');'], ...
                ['text(52,50,' [''' ' icon ''',''horizontalAlignment'',''center'');' newline]]   ...
                inport_label ...
                outport_label
                ];
        end

        function sts = getSampleTimeImpl(obj)
            sts = getSampleTimeImpl@matlabshared.sensors.simulink.internal.BlockSampleTime(obj);
        end
    end

    methods (Static, Access=protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end

        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end

    methods (Static)
        function name = getDescriptiveName()
            name = 'LEDC_INTERFACE';
        end

        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end

        function updateBuildInfo(buildInfo, context)
            coder.extrinsic('codertarget.targethardware.getTargetHardware');
            hCS = coder.const(getActiveConfigSet(bdroot));
            targetInfo = coder.const(codertarget.targethardware.getTargetHardware(hCS));

            % Added this env variable to fetch the comm libraries required only for Arduino target.
            % The env variable is cleared at the end of
            % "GenerateWrapperMakefile.m" file.
            if contains(targetInfo.TargetName,'arduinotarget')
                setenv('Arduino_ML_Codegen_I2C', 'Y');
            end



            buildInfo.addIncludePaths('C:\Users\obell\Documents\GitHub\Throttle_Body_Control_Platform\CODE\Research_And_Development\Matlab\ESP32_PWM');
            addSourceFiles(buildInfo,'LEDC_INTERFACE.cpp','C:\Users\obell\Documents\GitHub\Throttle_Body_Control_Platform\CODE\Research_And_Development\Matlab\ESP32_PWM');
            

        end
    end
end
