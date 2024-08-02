classdef ADS1115_Vread < matlab.System ...
        & coder.ExternalDependency ...
        & matlabshared.sensors.simulink.internal.BlockSampleTime

    % Single Ended Analog Voltage Read
    %#codegen
    %#ok<*EMCA>

    properties

    end

    properties(Access = protected)
        Logo = 'IO Device Builder';
    end

    properties (Nontunable)
        SetGain = int16(0);
    end

    properties (Access = private)


    end

    methods
        % Constructor
        function obj = ADS1115_Vread(varargin)
            setProperties(obj,nargin,varargin{:});
        end
    end

    methods (Access=protected)
        function setupImpl(obj)
            if ~coder.target('MATLAB')
                coder.cinclude('ADS1115_Vread.h');
                coder.ceval('setupFunctionADS1115_Vread', (obj.SetGain),1);
            end
        end

        function validateInputsImpl(obj,varargin)
            %  Check the input size
            if nargin ~=0



            end
        end

        function [V0,V1,V2,V3] = stepImpl(obj)
            V0 = double(zeros(1,1));
            V1 = double(zeros(1,1));
            V2 = double(zeros(1,1));
            V3 = double(zeros(1,1));
            if isempty(coder.target)
            else
                coder.ceval('stepFunctionADS1115_Vread',coder.ref(V0),1,coder.ref(V1),1,coder.ref(V2),1,coder.ref(V3),1);
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
            num = 0;
        end

        function num = getNumOutputsImpl(~)
            num = 4;
        end

        function varargout = getInputNamesImpl(obj)

        end

        function varargout = getOutputNamesImpl(obj)
            varargout{1} = 'V0';
            varargout{2} = 'V1';
            varargout{3} = 'V2';
            varargout{4} = 'V3';
        end

        function flag = isOutputSizeLockedImpl(~,~)
            flag = true;
        end

        function varargout = isOutputFixedSizeImpl(~,~)
            varargout{1} = true;
            varargout{2} = true;
            varargout{3} = true;
            varargout{4} = true;
        end

        function varargout = isOutputComplexImpl(~)
            varargout{1} = false;
            varargout{2} = false;
            varargout{3} = false;
            varargout{4} = false;
        end

        function varargout = getOutputSizeImpl(~)
            varargout{1} = [1,1];
            varargout{2} = [1,1];
            varargout{3} = [1,1];
            varargout{4} = [1,1];
        end

        function varargout = getOutputDataTypeImpl(~)
            varargout{1} = 'double';
            varargout{2} = 'double';
            varargout{3} = 'double';
            varargout{4} = 'double';
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
            icon = 'ADS1115_Vread';
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
            name = 'ADS1115_Vread';
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

username = getenv('USERNAME');  % Retrieve the username

% Corrected paths with fullfile
buildInfo.addIncludePaths(fullfile('C:\Users', username, 'Documents\GitHub\Throttle_Body_Control_Platform\CODE\Research_And_Development\Matlab\ESP32_ADC1115\libraries\Adafruit_ADS1X15'));
buildInfo.addIncludePaths(fullfile('C:\Users', username, 'Documents\GitHub\Throttle_Body_Control_Platform\CODE\Research_And_Development\Matlab\ESP32_ADC1115\libraries\Adafruit_BusIO'));
buildInfo.addIncludePaths(fullfile('C:\Users', username, 'Documents\GitHub\Throttle_Body_Control_Platform\CODE\Research_And_Development\Matlab\ESP32_ADC1115'));

% Adding source files with fullfile
addSourceFiles(buildInfo, 'Adafruit_ADS1X15.cpp', fullfile('C:\Users', username, 'Documents\GitHub\Throttle_Body_Control_Platform\CODE\Research_And_Development\Matlab\ESP32_ADC1115\libraries\Adafruit_ADS1X15'));
addSourceFiles(buildInfo, 'Adafruit_I2CDevice.cpp', fullfile('C:\Users', username, 'Documents\GitHub\Throttle_Body_Control_Platform\CODE\Research_And_Development\Matlab\ESP32_ADC1115\libraries\Adafruit_BusIO'));
addSourceFiles(buildInfo, 'ADS1115_Vread.cpp', fullfile('C:\Users', username, 'Documents\GitHub\Throttle_Body_Control_Platform\CODE\Research_And_Development\Matlab\ESP32_ADC1115'));
        end
    end
end
